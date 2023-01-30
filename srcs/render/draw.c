/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:55:15 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/30 16:55:11 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/*
	Re-maps a number from one range to another.
	First range : widths pixels
	Second range : FOV
	map(value, fromLow, fromHigh, toLow, toHigh)
	value: the number to map.
	fromLow: the lower bound of the value’s current range.
	fromHigh: the upper bound of the value’s current range.
	toLow: the lower bound of the value’s target range.
	toHigh: the upper bound of the value’s target range.
	https://www.arduino.cc/reference/en/language/functions/math/map/
	x		:	ou je suis actuellement entre 0 et largeur de fenetre
	in_min	:	colonne min, 0
	in_max	:	colonne max, WIN_WIDTH
	out_min	:	min range du FOV, 0 ou -30
	out_max	:	max range du FOV, 60 ou 30
*/
// float	map(long x, long in_min, long in_max, long out_min, long out_max)
// {
// 	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
// }
float	map(long x)
{
	return (x - 0.0) * (60.0 - 0.0) / (1024.0 - 0.0) + 0.0;
}

void	draw_column(t_global *global, long pos, int *x)
{
	int			i;
	int			taille_baton;
	int			temp;
	const int	colors[] = {BORDEAU, G_FAV, BLEUF};


	pos = 0;
	temp = 0;
	i = 0;
	dda(global, &global->ray, global->player.initial_angle);
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
}

void	draw_rainbow(t_global *global)
{
	int			column;
	long		pos;

	pos = 0;
	column = 0;
	while (column < WIN_WIDTH)
	{
		draw_column(global, pos, &column);
		++column;
	}
}

void	init_rainbow(t_global *global)
{
	create_image(&global->render_img, global->window.mlx_id, WIN_WIDTH, WIN_HEIGTH);
	draw_rainbow(global);
	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id, global->render_img.img, 0, 0);
}