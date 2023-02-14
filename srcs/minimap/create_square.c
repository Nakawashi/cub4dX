/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:08:37 by lgenevey          #+#    #+#             */
/*   Updated: 2023/02/14 11:11:39 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	draw colored square on the minimap
	careful: i and j build the image (line per line)
	x and y are position where to start to print, in the window
*/
void	my_mlx_put_square(t_img *img, t_vector2_d pos, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			his_mlx_pixel_put(img,
				j + pos.x * MINI_WIDTH,
				i + pos.y * MINI_WIDTH,
				color);
			++j;
		}
		++i;
	}
}
