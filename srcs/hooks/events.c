/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:43:13 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/09 20:41:56 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static void	move_north(t_player *player)
{
	player->y  -= 1; // on check pas ici les limites de la map mais si on est contre un mur on va pas
	printf("player horizontal :	[%d]\n", player->x);
	printf("player vertical : 	[%d]\n", player->y);
}

static void	move_south(t_player *player)
{
	player->y += 1;
	printf("player horizontal :	[%d]\n", player->x);
	printf("player vertical :	[%d]\n", player->y);
}
static void	move_east(t_player *player)
{
	player->x += 1;
	printf("player horizontal :	[%d]\n", player->x);
	printf("player vertical :	[%d]\n", player->y);
}
static void	move_west(t_player *player)
{
	player->x -= 1;
	printf("player horizontal :	[%d]\n", player->x);
	printf("player vertical :	[%d]\n", player->y);
}

int	key_hook(int keycode, t_global *global)
{
	if (keycode == KEY_ESC)
		clean(global);
	if (keycode == KEY_W)
	{
		move_north(&global->player);
		printf("you pressed w\n\n");
	}
	if (keycode == KEY_A)
	{
		move_west(&global->player);
		printf("you pressed a\n\n");
	}
	if (keycode == KEY_S)
	{
		move_south(&global->player);
		printf("you pressed s\n\n");
	}
	if (keycode == KEY_D)
	{
		move_east(&global->player);
		printf("you pressed d\n\n");
	}
	//display_player(global, global->player.x, global->player.y, COLOR);
	return (0);
}

/*
	mlx_key_hook : handle ESC, W, A, S, D
	mlx_hook : handle quit by closing window
*/
void	handle_events(t_global *global)
{
	mlx_hook(global->window.win_id, KEY_DOWN, 0, key_hook, &global);
	mlx_hook(global->window.win_id, ON_DESTROY, 0, clean, global);
}