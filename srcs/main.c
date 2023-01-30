/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:41:33 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/29 12:58:50 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	0 : x positif
	180 : x negatif
	90 : y positif
	270 : y negatif
*/

int	main(int argc, char **argv)
{
	t_global	global;
	(void)argc;
	(void)argv;

	init_interface(&global);
	global.player.position.x = coordinate_to_pixels(10);
	global.player.position.y = coordinate_to_pixels(4);
	global.player.initial_angle = degree_to_radians(90);
	global.player.speed = 1.5;

	init_minimap(&global);
	init_rainbow(&global); // comme ca la minimap s'affiche tt de suite
	init_player(&global, global.player.position, PINK); // position initiale du player
	player_direction(global.player.direction, global.player.initial_angle);
	handle_events(&global);
	mlx_loop(&global.window.mlx_id);
	return (0);
}
