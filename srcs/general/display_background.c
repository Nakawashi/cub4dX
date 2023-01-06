/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_background.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:10:32 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/06 18:33:47 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_image(t_global *global)
{
	init_img_struct(&global->floor_img);
	global->floor_img.line_length = WIN_WIDTH;
	global->floor_img.img = mlx_new_image(
		global->window.mlx_id,
		WIN_WIDTH,
		WIN_HEIGTH);
	global->floor_img.addr = mlx_get_data_addr(
		global->floor_img.img,
		&global->floor_img.bits_per_pixel,
		&global->floor_img.line_length,
		&global->floor_img.endian);
}

/*
	draw colored pixel (floor)
*/
void	my_mlx_put_floor(t_global *global, int x, int y, int color)
{
	int	i;
	int	j;

	create_image(global);
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

/*
	Une fonction par truc dans les fichiers et je les rassemble dans le main
	generate environment

*/
