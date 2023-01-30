/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:55:15 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/30 19:06:08 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_column(t_global *global, int *x)
{
	int			i;
	int			taille_baton;
	int			temp;
	long		actual_position;
	const int	colors[] = {BORDEAU, G_FAV, BLEUF};

	actual_position = global->player.initial_angle - (degree_to_radians(-30));
	temp = 0;
	i = 0;
	if (actual_position >= actual_position + 60)
		return ;
	dda(global, &global->ray, map(actual_position));
	printf("map : [%f]\n", map(actual_position));
	taille_baton = global->ray.ray_length;
	while (i < WIN_HEIGTH)
	{
		if (i <= WIN_HEIGTH / 2 - taille_baton / 2 || i > WIN_HEIGTH / 2 + taille_baton / 2)
			his_mlx_pixel_put(&global->render_img, *x, i, TRANSP);
		else
		{
			his_mlx_pixel_put(&global->render_img, *x, i, colors[temp/10]);
		}
		++i;
	}
	if (temp == 29)
		temp = -1;
	++temp;
	++actual_position;
}

void	draw_rainbow(t_global *global)
{
	int		column;

	column = 0;
	while (column < WIN_WIDTH)
	{
		draw_column(global, &column);
		++column;
	}
}

void	init_rainbow(t_global *global)
{
	create_image(&global->render_img, global->window.mlx_id, WIN_WIDTH, WIN_HEIGTH);
	draw_rainbow(global);
	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id, global->render_img.img, 0, 0);
}
