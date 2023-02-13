/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:43:13 by lgenevey          #+#    #+#             */
/*   Updated: 2023/02/13 21:06:04 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_forward(t_global *global)
{
	// si ou je vais ya un mur ou pas, ne pas avancer si oui
	t_vector2_f futur;

	futur = global->player.pos;
	// printf("\nactual X: %f\n", global->player.pos.x);
	// printf("actual Y: %f\n\n", global->player.pos.y);

	futur.x += cos(global->player.initial_angle) * global->player.speed;
	futur.y += sin(global->player.initial_angle) * global->player.speed;
	// printf("futur X: %f\n", futur.x);
	// printf("futur Y: %f\n\n", futur.y);

	// printf("actual coordonnee X: %d\n", pixels_to_coordinate(global->player.pos.x));
	// printf("actual coordonnee Y: %d\n", pixels_to_coordinate(global->player.pos.y));
	// printf("futur coordonnee X: %d\n", pixels_to_coordinate(futur.x));
	// printf("futur coordonnee Y: %d\n\n", pixels_to_coordinate(futur.y));


	// printf("futur X : %d\n", global->map_datas.map[pixels_to_coordinate(futur.y)][pixels_to_coordinate(futur.x)]);
	if (global->map_datas.map[pixels_to_coordinate(futur.y)][pixels_to_coordinate(futur.x)] == '0')
	{
		global->player.pos.x += cos(global->player.initial_angle) * global->player.speed;
		global->player.pos.y += sin(global->player.initial_angle) * global->player.speed;
	}

}

static void	move_backward(t_global *global)
{
	t_vector2_f futur;

	futur = global->player.pos;
	futur.x -= cos(global->player.initial_angle) * global->player.speed;
	futur.y -= sin(global->player.initial_angle) * global->player.speed;
	if (global->map_datas.map[pixels_to_coordinate(futur.y)][pixels_to_coordinate(futur.x)] == '0')
	{
		global->player.pos.x -= cos(global->player.initial_angle) * global->player.speed;
		global->player.pos.y -= sin(global->player.initial_angle) * global->player.speed;
	}
}
static void	move_right(t_global *global)
{
	t_vector2_f futur;

	futur = global->player.pos;
	futur.x += cos(global->player.initial_angle + degree_to_radians(90)) * global->player.speed;
	futur.y += sin(global->player.initial_angle + degree_to_radians(90)) * global->player.speed;
	if (global->map_datas.map[pixels_to_coordinate(futur.y)][pixels_to_coordinate(futur.x)] == '0')
	{
		global->player.pos.x += cos(global->player.initial_angle + degree_to_radians(90)) * global->player.speed;
		global->player.pos.y += sin(global->player.initial_angle + degree_to_radians(90)) * global->player.speed;
	}
}
static void	move_left(t_global *global)
{
	t_vector2_f futur;

	futur = global->player.pos;
	futur.x += cos(global->player.initial_angle + degree_to_radians(-90)) * global->player.speed;
	futur.y += sin(global->player.initial_angle + degree_to_radians(-90)) * global->player.speed;
	if (global->map_datas.map[pixels_to_coordinate(futur.y)][pixels_to_coordinate(futur.x)] == '0')
	{
		global->player.pos.y += sin(global->player.initial_angle + degree_to_radians(-90)) * global->player.speed;
		global->player.pos.x += cos(global->player.initial_angle + degree_to_radians(-90)) * global->player.speed;
	}
}

int	key_hook(int keycode, t_global *global)
{
	static int map = 0;
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
		global->player.initial_angle -= 0.08;
	if (keycode == ARROW_RIGHT)
		global->player.initial_angle += 0.08;
	if (keycode == 46) // KEY_M
		map = !map;

	draw_minimap(global); // clear minimap
	draw_rainbow(global);
	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id, global->render_img.img, 0, 0);

	if (map)
	{
		mlx_put_image_to_window(
			global->window.mlx_id,
			global->window.win_id,
			global->minimap.img, 0, 0);
		mlx_put_image_to_window(
			global->window.mlx_id,
			global->window.win_id,
			global->player.img.img,
			global->player.pos.x - 1.0,
			global->player.pos.y - 1.0);
	}
	return (0);
}

/*
	mlx loop hook
	faire fonction qui regroupe ca
		draw_minimap(global);
	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id,
		global->minimap.img, 0, 0);
	draw_player(global, global->player.pos);
	dda(global, &global->ray);
*/
void	handle_events(t_global *global)
{
	mlx_hook(global->window.win_id, KEY_DOWN, 0, key_hook, global);
	mlx_hook(global->window.win_id, ON_DESTROY, 0, clean, global);
}