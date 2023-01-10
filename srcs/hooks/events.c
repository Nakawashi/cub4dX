/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:43:13 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/10 18:38:00 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_forward(t_global *global)
{
	display_player(global, global->player.x, global->player.y, WHITE);

	global->player.x += cos(global->player.angle) * global->player.speed;
	global->player.y += sin(global->player.angle) * global->player.speed;

	display_player(global, global->player.x, global->player.y, COLOR);

	printf("player horizontal :	[%f]\n", global->player.x);
	printf("player vertical : 	[%f]\n", global->player.y);
}

static void	move_backward(t_global *global)
{
	display_player(global, global->player.x, global->player.y, WHITE);

	global->player.y += 1;
	display_player(global, global->player.x, global->player.y, COLOR);

	printf("player horizontal :	[%f]\n", global->player.x);
	printf("player vertical :	[%f]\n", global->player.y);
}
static void	move_right(t_global *global)
{
	display_player(global, global->player.x, global->player.y, WHITE);

	global->player.x += 1;
	display_player(global, global->player.x, global->player.y, COLOR);

	printf("player horizontal :	[%f]\n", global->player.x);
	printf("player vertical :	[%f]\n", global->player.y);
}
static void	move_left(t_global *global)
{
	display_player(global, global->player.x, global->player.y, WHITE);

	global->player.x -= 1;
	display_player(global, global->player.x, global->player.y, COLOR);

	printf("player horizontal :	[%f]\n", global->player.x);
	printf("player vertical :	[%f]\n", global->player.y);
}

int	key_hook(int keycode, t_global *global)
{
	// float	step;

	// step = global->player.speed;
	// while (global->player.x > MINI_WIDTH && global->player.x < MINI_WIDTH * global->map_datas.map_width)
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