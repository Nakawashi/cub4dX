/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:43:13 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/10 15:46:03 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// position = speed *  x
// position = speed *  y

static void	move_north(t_global *global)
{
	display_player(global, global->player.x, global->player.y, WHITE);

	global->player.y  -= 1; // on check pas ici les limites de la map mais si on est contre un mur on va pas
	display_player(global, global->player.x, global->player.y, COLOR);

	printf("player horizontal :	[%d]\n", global->player.x);
	printf("player vertical : 	[%d]\n", global->player.y);
}

static void	move_south(t_global *global)
{

	global->player.y += 1;
	printf("player horizontal :	[%d]\n", global->player.x);
	printf("player vertical :	[%d]\n", global->player.y);
}
static void	move_east(t_global *global)
{
	global->player.x += 1;
	printf("player horizontal :	[%d]\n", global->player.x);
	printf("player vertical :	[%d]\n", global->player.y);
}
static void	move_west(t_global *global)
{
	global->player.x -= 1;
	printf("player horizontal :	[%d]\n", global->player.x);
	printf("player vertical :	[%d]\n", global->player.y);
}

int	key_hook(int keycode, t_global *global)
{
	if (keycode == KEY_ESC)
		clean(global);
	if (keycode == KEY_W)
	{
		move_north(global);
		printf("you pressed w\n\n");
	}
	if (keycode == KEY_A)
	{
		move_west(global);
		printf("you pressed a\n\n");
	}
	if (keycode == KEY_S)
	{
		move_south(global);
		printf("you pressed s\n\n");
	}
	if (keycode == KEY_D)
	{
		move_east(global);
		printf("you pressed d\n\n");
	}
	return (0);
}

/*
	mlx_key_hook : handle ESC, W, A, S, D
	mlx_hook : handle quit by closing window
*/
void	handle_events(t_global *global)
{
	mlx_hook(global->window.win_id, KEY_DOWN, 0, key_hook, global);
	mlx_hook(global->window.win_id, ON_DESTROY, 0, clean, global);
}