/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:55:15 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/29 13:02:20 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rainbow(t_global *global)
{
	int			column;
	int			line;
	int			i;
	const int	colors[] = {BORDEAU, G_FAV, BLEUF};

	i = 0;
	line = 0;
	while (line < WIN_WIDTH)
	{
		column = 0;
		while (column < WIN_HEIGTH)
		{
			if (column <= 250)
				his_mlx_pixel_put(&global->render_img, line, column, TRANSP);
			else if (column < 350)
				his_mlx_pixel_put(&global->render_img, line, column, colors[i/10]);
			else
				his_mlx_pixel_put(&global->render_img, line, column, TRANSP);
			++column;
		}
		if (i == 29)
			i = -1;
		++i;
		++line;
	}
}

void	init_rainbow(t_global *global)
{
	create_image(&global->render_img, global->window.mlx_id, WIN_WIDTH, WIN_HEIGTH);
	draw_rainbow(global);
	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id, global->render_img.img, 0, 0);
}