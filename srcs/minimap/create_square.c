/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:08:37 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/09 17:03:22 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	draw colored square for the minimap
	careful: i and j build the image (line per line)
	x and y are position where to start to prin, in the window
*/
void	my_mlx_put_square(t_global *global, t_img *img, int x, int y, int color)
{
	int	i;
	int	j;
	// (void)x;
	// (void)y;

	//create_image(&global->minimap, global->window.mlx_id, MINI_WIDTH, MINI_HEIGHT);
	i = 0;
	while(i < MINI_HEIGHT)
	{
		j = 0;
		while (j < MINI_WIDTH)
		{
			his_mlx_pixel_put(img, j, i, color);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id,
		global->minimap.img, x, y);
}
