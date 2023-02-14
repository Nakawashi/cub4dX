/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:59:03 by lgenevey          #+#    #+#             */
/*   Updated: 2023/02/14 11:11:48 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

enum e_minimap
{
	MINI_FLOOR = '0',
	MINI_WALL = '1',
};

void	draw_minimap(t_global *global)
{
	t_vector2_d	pos;

	pos.y = -1;
	while (global->map_datas.map[++pos.y])
	{
		pos.x = -1;
		while (global->map_datas.map[pos.y][++pos.x])
		{
			if (global->map_datas.map[pos.y][pos.x] == MINI_WALL)
				my_mlx_put_square(&global->minimap, pos, MINI_WIDTH, BLACK);
			else
				my_mlx_put_square(&global->minimap, pos, MINI_WIDTH, WHITE);
		}
	}
}

/*
	let mlx_put_image_to_window here
*/
void	init_minimap(t_global *global)
{
	create_image(&global->minimap,
		global->window.mlx_id,
		MINI_WIDTH * global->map_datas.map_width,
		MINI_HEIGHT * global->map_datas.map_height);
	draw_minimap(global);
	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id,
		global->minimap.img, 0, 0);
}
