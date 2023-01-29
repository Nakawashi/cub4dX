/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:05:42 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/27 19:11:19 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_parsing(t_global *global);

/*
	init t_window datas
*/
void	init_window(t_window *window)
{
	window->mlx_id = mlx_init();
	window->win_id = mlx_new_window(window->mlx_id, WIN_WIDTH, WIN_HEIGTH,
		"Half Life 3.2");
}

void	init_interface(t_global *global, char *map)
{
	init_window(&global->window);
	display_background(global, 0, 0);

	init_parsing(global);
	if (read_file(global, map) < 0)
		exit(1);


	printf("%d %d\n", global->map_datas.map_width, global->map_datas.map_height);

	printf("path no %s\n", global->no.texture_path);
	printf("path so %s\n", global->so.texture_path);
	printf("path we %s\n", global->we.texture_path);
	printf("path ea %s\n", global->ea.texture_path);
	printf("color ceil %s\n", global->window.color_ceiling_hexa);
	printf("color floor %s\n", global->window.color_floor_hexa);
	

	// global->map_datas.map = read_map("assets/map1.cub");
	// if (!global->map_datas.map)
	// 	exit (1);
	// get_map_height(&global->map_datas);
}

static void	init_parsing(t_global *global)
{
	global->map_datas.map = NULL;
	global->map_datas.map_width = 0;
	global->map_datas.map_height = 0;
	global->player.position.x = -1;

	global->window.color_ceiling_hexa = NULL;
	global->window.color_floor_hexa = NULL;

	ft_bzero(&global->no, sizeof(t_img));
	ft_bzero(&global->so, sizeof(t_img));
	ft_bzero(&global->we, sizeof(t_img));
	ft_bzero(&global->ea, sizeof(t_img));
}