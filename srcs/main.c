/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:41:33 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/13 20:09:26 by lgenevey         ###   ########.fr       */
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

	init_window(&global.window); // init basics, winodw, quit, display bckg...

	global.map_datas.map = read_map("assets/map1.cub");
	if (!global.map_datas.map)
		return (1);
	get_map_height(&global.map_datas);
	global.player.position.x = coordinate_to_pixels(10);
	global.player.position.y = coordinate_to_pixels(4);
	global.player.angle = degree_to_radians(-90);


for (int i = 0; i < global.map_datas.map_height; ++i)
	printf("%s\n", global.map_datas.map[i]);

	my_mlx_put_ceiling(&global, 0, 0, BLEU);
	my_mlx_put_floor(&global, 0, WIN_HEIGTH/2, JAUNE);
	init_minimap(&global);

	printf("global.player.x : %f\n", global.player.position.x);
	printf("global.player.y : %f\n", global.player.position.y);

	init_player(&global, global.player.position, PINK); // position initiale du player
	player_direction(global.player.direction, global.player.angle);
	global.player.speed = 1;

	handle_events(&global);
	mlx_loop(&global.window.mlx_id);
	return (0);
}
