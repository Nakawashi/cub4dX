/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:05:48 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/09 19:26:29 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

enum e_minimap
{
	MINI_FLOOR = '0',
	MINI_WALL = '1',
};



/*
	Run through the map and display *img where its letter is placed
	Get player coordinate and direction
	Try to read less times as possible
*/
void	init_minimap(t_global *global)
{
	int		i;
	int		j;

	// create_image(&global->minimap,
	// 	global->window.mlx_id,
	// 	MINI_WIDTH * global->map_datas.map_width,
	// 	MINI_HEIGHT * global->map_datas.map_height);
		create_image(&global->minimap,
		global->window.mlx_id,
		MINI_WIDTH,
		MINI_HEIGHT);

	i = -1;
	while (global->map_datas.map[++i])
	{
		j = -1;
		while (global->map_datas.map[i][++j])
		{
			if (global->map_datas.map[i][j] == MINI_WALL)
			{
				my_mlx_put_square(global, &global->minimap, j * MINI_WIDTH, i * MINI_HEIGHT, BLACK);
			}
			else if (global->map_datas.map[i][j] == 'N'
				|| global->map_datas.map[i][j] == 'S'
				|| global->map_datas.map[i][j] == 'E'
				|| global->map_datas.map[i][j] == 'W')
				{
					my_mlx_put_square(global, &global->minimap, j * MINI_WIDTH, i * MINI_HEIGHT, WHITE);
					global->player.x = coordinate_to_pixels(j);
					global->player.y = coordinate_to_pixels(i);
				}
			else
			{
				my_mlx_put_square(global, &global->minimap, j * MINI_WIDTH, i * MINI_HEIGHT, WHITE);
			}
		}
	}
}

void	display_minimap(t_global *global)
{
	int		i;
	int		j;

	i = -1;
	while (global->map_datas.map[++i])
	{
		j = -1;
		while (global->map_datas.map[i][++j])
		{
			if (global->map_datas.map[i][j] == MINI_WALL)
			{
				my_mlx_put_square(global, &global->minimap, j * MINI_WIDTH, i * MINI_HEIGHT, BLACK);
			}
			else
			{
				my_mlx_put_square(global, &global->minimap, j * MINI_WIDTH, i * MINI_HEIGHT, WHITE);
			}
		}
	}
}

// void	init_minimap(t_global *global)
// {
// 	int		i;
// 	int		j;

// 	create_image(&global->minimap,
// 		global->window.mlx_id,
// 		MINI_WIDTH * global->map_datas.map_width,
// 		MINI_HEIGHT * global->map_datas.map_height);

// printf("wid:	[%d] -- map wid:	[%d] -- produit:	[%d]\n", MINI_WIDTH, global->map_datas.map_width, MINI_WIDTH * global->map_datas.map_width);
// printf("hei:	[%d] -- map hei:	[%d] -- produit:	[%d]\n", MINI_HEIGHT, global->map_datas.map_height, MINI_HEIGHT * global->map_datas.map_height);

// 	i = -1;
// 	while (global->map_datas.map[++i])
// 	{
// 		j = -1;
// 		while (global->map_datas.map[i][++j])
// 		{
// 			if (global->map_datas.map[i][j] == MINI_WALL)
// 				my_mlx_put_square(&global->minimap, j * MINI_WIDTH, i * MINI_HEIGHT, BLACK);
// 			else if (global->map_datas.map[i][j] == 'N'
// 				|| global->map_datas.map[i][j] == 'S'
// 				|| global->map_datas.map[i][j] == 'E'
// 				|| global->map_datas.map[i][j] == 'W')
// 			{
// 				my_mlx_put_square(&global->minimap, j * MINI_WIDTH, i * MINI_HEIGHT, WHITE);
// 				//global->player.direction = global->map_datas.map[i][j];
// 				global->player.x = coordinate_to_pixels(j);
// 				global->player.y = coordinate_to_pixels(i);
// 				//my_mlx_put_player(global, global->player.x, global->player.y, COLOR);
// 			}
// 			else
// 				my_mlx_put_square(&global->minimap, j * MINI_WIDTH, i * MINI_HEIGHT, WHITE);
// 		}
// 	}
// 	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id,
// 		global->minimap.img, 0, 0);
// }
