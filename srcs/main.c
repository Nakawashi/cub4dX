/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:41:33 by lgenevey          #+#    #+#             */
/*   Updated: 2023/02/14 16:42:34 by lgenevey         ###   ########.fr       */
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
		init_interface(&global, "assets/cub/map1v2.cub");
	global.player.speed = 0.8;
	init_rainbow(&global);
	init_minimap(&global);
	init_player(&global, global.player.pos, PINK);
	handle_events(&global);
	mlx_loop(&global.window.mlx_id);
	return (0);
}
