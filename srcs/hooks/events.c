/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:43:13 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/13 14:45:55 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_forward(t_global *global)
{
	display_player(global, &global->player.position, WHITE);
	global->player.position.x += cos(global->player.angle - degree_to_radians(90)) * global->player.speed;
	global->player.position.y += sin(global->player.angle - degree_to_radians(90)) * global->player.speed;
	display_player(global, &global->player.position, COLOR);

	printf("player horizontal :	[%f]\n", global->player.position.x);
	printf("player vertical : 	[%f]\n", global->player.position.y);
}

static void	move_backward(t_global *global)
{
	display_player(global, &global->player.position, WHITE);
	global->player.position.x += cos(global->player.angle + degree_to_radians(90)) * global->player.speed;
	global->player.position.y += sin(global->player.angle + degree_to_radians(90)) * global->player.speed;
	display_player(global, &global->player.position, COLOR);
}
static void	move_right(t_global *global)
{
	display_player(global, &global->player.position, WHITE);
	global->player.position.x += cos(global->player.angle) * global->player.speed;
	global->player.position.y += sin(global->player.angle) * global->player.speed;
	display_player(global, &global->player.position, COLOR);
}
static void	move_left(t_global *global)
{
	display_player(global, &global->player.position, WHITE);
	global->player.position.x -= cos(global->player.angle) * global->player.speed;
	global->player.position.y -= sin(global->player.angle) * global->player.speed;
	display_player(global, &global->player.position, COLOR);
}

int	key_hook(int keycode, t_global *global)
{
	if (keycode == KEY_ESC)
		clean(global);
	if (keycode == KEY_W)
	{
		move_forward(global);
		printf("you pressed w\n\n");
	}
	if (keycode == KEY_A)
	{
		move_left(global);
		printf("you pressed a\n\n");
	}
	if (keycode == KEY_S)
	{
		move_backward(global);
		printf("you pressed s\n\n");
	}
	if (keycode == KEY_D)
	{
		move_right(global);
		printf("you pressed d\n\n");
	}
	return (0);
}

void	handle_events(t_global *global)
{
	mlx_hook(global->window.win_id, KEY_DOWN, 0, key_hook, global);
	mlx_hook(global->window.win_id, ON_DESTROY, 0, clean, global);
}