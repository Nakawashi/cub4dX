/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_background.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:10:32 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/02 20:43:55 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->texture_path = NULL;
	img->img_width = 0;
	img->img_height = 0;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
}

void	build_bg_img(t_window *window, t_img *img)
{
	init_img(img);
	img->line_length = window->win_width;
	img->img = mlx_new_image(
		window->mlx_id,
		window->win_height,
		window->win_width);
	img->addr = mlx_get_data_addr(
		img->img,
		&img->bits_per_pixel,
		&img->line_length,
		&img->endian);
}

void	my_mlx_put_rectangle(t_global *global)
{
	int	i;
	int	j;

	i = 0;
	while(i < global->window.win_height)
	{
		j = 0;
		build_bg_img(&global->window, &global->img);
		my_mlx_pixel_put(&global->img, i, j, 0x00FF0000);
		while (j < global->window.win_width)
		{
			mlx_put_image_to_window(
				global->window.mlx_id,
				global->window.win_id,
				global->img.img,
				i,
				i);
				++j;
		}
		++i;
	}
}
/*
	Une fonction par truc dans les fichiers et je les rassemble dans le main
	generate environment

*/