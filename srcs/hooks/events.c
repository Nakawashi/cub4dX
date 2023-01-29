/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:43:13 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/27 18:48:18 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	mlx_put_image_to_window boring to write
*/
void	draw_player(t_global *global, t_vector2_f pos)
{
	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id,
		global->player.img.img, pos.x, pos.y);
}

static void	move_forward(t_global *global)
{
	global->player.position.x += cos(global->player.initial_angle) * global->player.speed;
	global->player.position.y += sin(global->player.initial_angle) * global->player.speed;
}

static void	move_backward(t_global *global)
{
	global->player.position.x -= cos(global->player.initial_angle) * global->player.speed;
	global->player.position.y -= sin(global->player.initial_angle) * global->player.speed;
}
static void	move_right(t_global *global)
{
	global->player.position.x += cos(global->player.initial_angle + degree_to_radians(90)) * global->player.speed;
	global->player.position.y += sin(global->player.initial_angle + degree_to_radians(90)) * global->player.speed;
}
static void	move_left(t_global *global)
{
	global->player.position.x += cos(global->player.initial_angle + degree_to_radians(-90)) * global->player.speed;
	global->player.position.y += sin(global->player.initial_angle + degree_to_radians(-90)) * global->player.speed;
}

int	key_hook(int keycode, t_global *global)
{
	int	i;

	if (keycode == KEY_ESC)
		clean(global);
	if (keycode == KEY_W)
		move_forward(global);
	if (keycode == KEY_A)
		move_left(global);
	if (keycode == KEY_S)
		move_backward(global);
	if (keycode == KEY_D)
		move_right(global);
	if (keycode == ARROW_LEFT)
		global->player.initial_angle -= 0.05;
	if (keycode == ARROW_RIGHT)
		global->player.initial_angle += 0.05;
	draw_minimap(global); // clear minimap
	i = 30;
	while (i >= 0)
	{
		dda(global, &global->ray, global->player.initial_angle - (degree_to_radians(i)));
		i--;
	}
	dda(global, &global->ray, global->player.initial_angle);
	i = 0;
	while (i < 30)
	{
		dda(global, &global->ray, global->player.initial_angle + (degree_to_radians(i)));
		i++;
	}
	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id,
		global->minimap.img, 0, 0); // display minimap PLUS dda
	draw_player(global, global->player.position);
	printf("player.position.x :	[%f]\n", global->player.position.x);
	printf("player.position.y :	[%f]\n", global->player.position.y);
	return (0);
}

/*
	mlx loop hook
	faire fonction qui regroupe ca
		draw_minimap(global);
	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id,
		global->minimap.img, 0, 0);
	draw_player(global, global->player.position);
	dda(global, &global->ray);
*/
void	handle_events(t_global *global)
{
	mlx_hook(global->window.win_id, KEY_DOWN, 0, key_hook, global);
	mlx_hook(global->window.win_id, ON_DESTROY, 0, clean, global);
}