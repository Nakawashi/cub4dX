/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:41:33 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/10 18:30:38 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// jaune:	0x00FFCE6D
// bleu:	0x0081D5FF

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

for (int i = 0; i < global.map_datas.map_height; ++i)
	printf("%s\n", global.map_datas.map[i]);

	my_mlx_put_ceiling(&global, 0, 0, BLEU);
	my_mlx_put_floor(&global, 0, WIN_HEIGTH/2, JAUNE);
	init_minimap(&global);

	printf("global.player.x : %f\n", global.player.x);
	printf("global.player.y : %f\n", global.player.y);

	init_player(&global, global.player.x, global.player.y, COLOR); // position initiale du player
	if (global.player.direction == 'N')
		global.player.angle = degree_to_radians(-90);
	if (global.player.direction == 'W')
		global.player.angle = degree_to_radians(180);
	if (global.player.direction == 'E')
		global.player.angle = degree_to_radians(0);
	if (global.player.direction == 'S')
		global.player.angle = degree_to_radians(90);
	global.player.speed = 0.2;

	handle_events(&global);
	mlx_loop(&global.window.mlx_id);
	return (0);
}
