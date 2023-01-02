/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:41:33 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/02 20:01:38 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_global	global;
	t_map		map;
	(void)argc;
	(void)argv;

	init_window(&global.window);
	quit_program(&global.window);
	map.map = read_map("assets/map1.cub");
	if (!map.map)
		return (0);
	for (int i = 0; i < 5; ++i)
		printf("%s\n", map.map[i]);
	create_bg_img(&global.window, &global.img);
	my_mlx_pixel_put(&global.img, 5, 5, 0x00FF0000);
	printf("\n");
	mlx_put_image_to_window(
		global.window.mlx_id,
		global.window.win_id,
		global.img.img,
		0,
		0);
	mlx_loop(&global.window.mlx_id);
	return (0);
}
