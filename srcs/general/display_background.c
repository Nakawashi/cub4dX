/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_background.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:10:32 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/27 19:12:15 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	draw the floor and the ceiling.
	Identical but keep for now for better understanding

	careful: i and j build the image (line per line)
	x and y are position where to start to prin, in the window
*/
void	init_background(t_global *global, int x, int y)
{
	int	i;
	int	j;
	int	k;

	k = 32;
	create_image(&global->background_img,
		global->window.mlx_id, WIN_WIDTH, WIN_HEIGTH);
	i = 0;
	while (i < WIN_HEIGTH)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			if (i < WIN_HEIGTH / 2)
				his_mlx_pixel_put(&global->background_img, j, i, BLEU);
			else
				his_mlx_pixel_put(&global->background_img, j, i, JAUNE);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id,
		global->background_img.img, x, y);
}
