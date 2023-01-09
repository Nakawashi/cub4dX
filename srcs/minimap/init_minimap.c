/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:05:48 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/08 17:33:58 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

enum e_minimap
{
	MINI_FLOOR = '0',
	MINI_WALL = '1',
};

void	my_mlx_put_player(t_global *global, int x, int y, int color)
{
	int	i;
	int	j;

	create_image(&global->minimap, global->window.mlx_id,
		4, 4);
	i = 0;
	while(i < 4)
	{
		j = 0;
		while (j < 4)
		{
			his_mlx_pixel_put(&global->minimap, j, i, color);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id,
		global->minimap.img, x, y);
}

/*
	Run through the map and display *img where its letter is placed
	Get player coordinate and direction
	Try to read less times as possible
*/
void	init_minimap(t_global *global)
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
				my_mlx_put_square(global, j * MINI_WIDTH, i * MINI_HEIGHT, BLACK);
			else if (global->map_datas.map[i][j] == 'N'
				|| global->map_datas.map[i][j] == 'S'
				|| global->map_datas.map[i][j] == 'E'
				|| global->map_datas.map[i][j] == 'W')
				{
					my_mlx_put_square(global, j * MINI_WIDTH, i * MINI_HEIGHT, WHITE);
					global->player.direction = global->map_datas.map[i][j];
					global->player.x = coordinate_to_pixels(j);
					global->player.y = coordinate_to_pixels(i);
					my_mlx_put_player(global, global->player.x, global->player.y, COLOR);
				}
			else
				my_mlx_put_square(global, j * MINI_WIDTH, i * MINI_HEIGHT, WHITE);
		}
	}
}
// void	init_minimap(t_global *global)
// {
// 	int		i;
// 	int		j;

// 	i = -1;
// 	while (global->map_datas.map[++i])
// 	{
// 		j = -1;
// 		while (global->map_datas.map[i][++j])
// 		{
// 			if (global->map_datas.map[i][j] == MINI_WALL)
// 				my_mlx_put_sqare(global, j * MINI_WIDTH, i * MINI_HEIGHT, BLACK);
// 			else if (global->map_datas.map[i][j] == 'N'
// 				|| global->map_datas.map[i][j] == 'S'
// 				|| global->map_datas.map[i][j] == 'E'
// 				|| global->map_datas.map[i][j] == 'W')
// 				mlx_pixel_put(global->window.mlx_id,
// 					global->window.win_id,
// 					j * MINI_WIDTH,
// 					i * MINI_HEIGHT, COLOR);
// 			else
// 				my_mlx_put_sqare(global, j * MINI_WIDTH, i * MINI_HEIGHT, WHITE);
// 		}
// 	}
// }
