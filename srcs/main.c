/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:41:33 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/28 00:15:10 by lgenevey         ###   ########.fr       */
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

	// init_window(&global.window); // init basics, winodw, quit, display bckg...
	// quit_program(&global);
	if (argc > 1)
		init_interface(&global, argv[1]);
	else
		init_interface(&global, "assets/arx.cub");

	// for (int i = 0; i < global.map_datas.map_height; ++i)
	// 	printf("%s\n", global.map_datas.map[i]);
	global.player.speed = 1.5;

	display_rainbow(&global); // comme ca la minimap s'affiche tt de suite
	init_minimap(&global);
	init_player(&global, global.player.position, PINK); // position initiale du player
	handle_events(&global);
	mlx_loop(&global.window.mlx_id);


	return (0);
}
