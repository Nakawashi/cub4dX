/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:08:37 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/08 14:31:49 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	draw colored square for the minimap
	careful: i and j build the image (line per line)
	x and y are position where to start to prin, in the window
*/
void	my_mlx_put_square(t_global *global, int x, int y, int color)
{
	int	i;
	int	j;

	create_image(&global->minimap, global->window.mlx_id,
		MINI_WIDTH, MINI_HEIGHT);
	i = 0;
	while(i < MINI_HEIGHT)
	{
		j = 0;
		while (j < MINI_WIDTH)
		{
			his_mlx_pixel_put(&global->minimap, j, i, color);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id,
		global->minimap.img, x, y);
}