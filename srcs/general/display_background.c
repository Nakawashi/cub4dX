/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_background.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:10:32 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/02 22:44:35 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_img_struct(t_img *img)
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
	init_img_struct(img);
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
	Creates a rectangle, store it in gene
*/
void	my_mlx_put_rectangle(t_global *global, int i, int j)
{
	int	i;
	int	j;

	build_bg_img(&global->window, &global->bg_img);
	i = 0;
	while(i < global->window.win_height)
	{
		j = 0;
		while (j < global->window.win_width)
		{
			my_mlx_pixel_put(&global->bg_img, i, j, 0x00FF0000);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(
		global->window.mlx_id,
		global->window.win_id,
		global->bg_img.img,
		0,
		0);
}
/*
	Une fonction par truc dans les fichiers et je les rassemble dans le main
	generate environment

*/
