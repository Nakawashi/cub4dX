/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_background.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:10:32 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/07 14:01:54 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	draw the floor and the ceiling. Identical but keep for now for better understanding
	
	careful: i and j build the image (line per line)
	x and y are position where to start to prin, in the window
*/
void	my_mlx_put_floor(t_global *global, int x, int y, int color)
{
	int	i;
	int	j;

	create_image(&global->floor_img, global->window.mlx_id,
		WIN_WIDTH, WIN_HEIGTH/2);
	i = 0;
	while(i < WIN_HEIGTH/2)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			my_mlx_pixel_put(&global->floor_img, j, i, color);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id,
		global->floor_img.img, x, y);
}

void	my_mlx_put_ceiling(t_global *global, int x, int y, int color)
{
	int	i;
	int	j;

	create_image(&global->ceiling_img, global->window.mlx_id,
		WIN_WIDTH, WIN_HEIGTH/2);
	i = x;
	while(i < WIN_HEIGTH/2)
	{
		j = y;
		while (j < WIN_WIDTH)
		{
			my_mlx_pixel_put(&global->ceiling_img, j, i, color);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id,
		global->ceiling_img.img, x, y);
}
