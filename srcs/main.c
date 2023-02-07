/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:41:33 by lgenevey          #+#    #+#             */
/*   Updated: 2023/02/07 15:06:04 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	0 : x positif
	180 : x negatif
	90 : y positif
	270 : y negatif
*/

/*
	Fix player movements (coordinates now)
	Put some textures
	Can't pass through the walls
*/

int	main(int argc, char **argv)
{
	t_global	global;

	if (argc > 1)
		init_interface(&global, argv[1]);
	else
		init_interface(&global, "assets/map1v2.cub");
	global.player.speed = 0.5;
	init_rainbow(&global); // comme ca la minimap s'affiche tt de suite
	init_minimap(&global);
	init_player(&global, global.player.pos, PINK); // position initiale du player
	handle_events(&global);
	mlx_loop(&global.window.mlx_id);


	return (0);
}
