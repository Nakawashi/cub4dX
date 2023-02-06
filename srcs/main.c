/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:41:33 by lgenevey          #+#    #+#             */
/*   Updated: 2023/02/06 16:38:36 by lgenevey         ###   ########.fr       */
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

	if (argc > 1)
		init_interface(&global, argv[1]);
	else
		init_interface(&global, "assets/map1v2.cub");
	global.player.speed = 0.75;
	init_rainbow(&global); // comme ca la minimap s'affiche tt de suite
	init_minimap(&global);
	init_player(&global, global.player.pos, PINK); // position initiale du player
	handle_events(&global);
	/*

	get wall positions
		leurs coordonnees, ensuite on sait que 
	get actual player position --> dans les events
	comparer ces positions avec la position d'ou se trouvent les murs


	*/
	mlx_loop(&global.window.mlx_id);


	return (0);
}
