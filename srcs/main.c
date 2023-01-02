/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:41:33 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/02 22:43:23 by nakawashi        ###   ########.fr       */
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
/* 	build_bg_img(&global.window, &global.bg_img);
	for (int i = 0; i < 500; ++i)
		my_mlx_pixel_put(&global.bg_img, i, 100, 0x00FF0000);
	mlx_put_image_to_window(
		global.window.mlx_id,
		global.window.win_id,
		global.bg_img.img,
		0,
		0); */
	my_mlx_put_rectangle(&global);
	mlx_loop(&global.window.mlx_id);
	return (0);
}
