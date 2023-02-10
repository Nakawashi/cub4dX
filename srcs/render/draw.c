/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:55:15 by lgenevey          #+#    #+#             */
/*   Updated: 2023/02/10 15:51:36 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	map():
	prend la position de la colonne entre 0 et 1024 et rend une valeur
	entre -30 et 30, ce qui correspond a l'angle
	taille_baton:
	inverser, plus c'est loin plus c'est petit mais plus le rayon est long
*/
void	draw_column(t_global *global, int *x)
{
	int	i;
	int	taille_baton;
	int	color;
	int	wall_start;

	dda(global, &global->ray, global->player.initial_angle - degree_to_radians(map(*x) - 30));
	taille_baton = (4000/global->ray.ray_length);
	i = 0;
	wall_start = WIN_HEIGTH / 2 - taille_baton / 2;
	while (i < WIN_HEIGTH)
	{
		if (i <= WIN_HEIGTH / 2 - taille_baton / 2)
		{
			his_mlx_pixel_put(&global->render_img, *x, i, global->window.color_ceiling_int);
		}
		else if (i > WIN_HEIGTH / 2 + taille_baton / 2)
		{
			his_mlx_pixel_put(&global->render_img, *x, i, global->window.color_floor_int);
		}
		else
		{
			if (global->ray.side_hit == 'n')
			{
				// if (global->ray.wallX < 0.4) // V
				if (i - wall_start < taille_baton * 0.4) // H
					color = G_FAV;
				else
					color = BLACK;
				his_mlx_pixel_put(&global->render_img, *x, i, color);
			}
			else if (global->ray.side_hit == 's')
				his_mlx_pixel_put(&global->render_img, *x, i, color);
			else if (global->ray.side_hit == 'e')
			{
				his_mlx_pixel_put(&global->render_img, *x, i, color);
			}
			else if (global->ray.side_hit == 'w')
				his_mlx_pixel_put(&global->render_img, *x, i, color);
		}
		++i;
	}
}


/*
	column is ---->
*/
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
