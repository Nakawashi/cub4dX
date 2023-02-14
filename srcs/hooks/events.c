/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:43:13 by lgenevey          #+#    #+#             */
/*   Updated: 2023/02/14 16:57:28 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	show_map(t_global *global)
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

int	key_hook(int keycode, t_global *global)
{
	static int	map = 0;

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
		global->player.initial_angle -= deg_to_rad(5);
	if (keycode == ARROW_RIGHT)
		global->player.initial_angle += deg_to_rad(5);
	if (keycode == 46)
		map = !map;
	draw_minimap(global);
	draw_rainbow(global);
	mlx_put_image_to_window(global->window.mlx_id,
		global->window.win_id, global->render_img.img, 0, 0);
	if (map)
		show_map(global);
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
