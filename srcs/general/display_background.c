/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_background.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:10:32 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/06 19:41:18 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_image(t_img *img, t_window *mlx_id)
{
	init_img_struct(img);
	img->line_length = WIN_WIDTH;
	img->img = mlx_new_image(mlx_id, WIN_WIDTH, WIN_HEIGTH);
	img->addr = mlx_get_data_addr(
		img->img,
		&img->bits_per_pixel,
		&img->line_length,
		&img->endian);
}

/*
	draw colored pixel (floor)
*/
void	my_mlx_put_floor(t_global *global, int x, int y, int color)
{
	int	i;
	int	j;

	create_image(&global->floor_img, global->window.mlx_id);
	i = x;
	while(i < WIN_HEIGTH)
	{
		j = y;
		while (j < WIN_WIDTH)
		{
			my_mlx_pixel_put(&global->floor_img, j, i, color);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id,
		global->floor_img.img, 0, 0);
}

void	my_mlx_put_ceiling(t_global *global, int x, int y, int color)
{
	int	i;
	int	j;

	create_image(&global->ceiling_img, global->window.mlx_id);
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
		global->ceiling_img.img, 0, 0);
}
