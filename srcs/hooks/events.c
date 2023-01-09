/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:43:13 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/09 18:21:01 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_north(t_player *player)
{
	player->y  -= 1; // on check pas ici les limites de la map mais si on est contre un mur on va pas
	printf("player horizontal : [%d]\n", player->x);
	printf("player vertical : [%d]\n", player->y);
}

int	key_hook(int keycode, t_global *global)
{
	if (keycode == EVENT_KEY_ESC)
		clean(global);
	if (keycode == KEY_W)
	{
		move_north(&global->player);
		printf("you pressed w\n");
	}
	if (keycode == KEY_A)
		printf("you pressed a\n");
	if (keycode == KEY_S)
		printf("you pressed s\n");
	if (keycode == KEY_D)
		printf("you pressed d\n");
	return (0);
}