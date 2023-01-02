/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_background.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:10:32 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/02 19:40:18 by lgenevey         ###   ########.fr       */
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

void	create_bg_img(t_window	*window, t_img *img)
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

/*

*/
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;

}

/*
	Une fonction par truc dans les fichiers et je les rassemble dans le main
	generate environment

*/