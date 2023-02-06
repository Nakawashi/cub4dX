/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:55:15 by lgenevey          #+#    #+#             */
/*   Updated: 2023/02/02 23:02:38 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_column(t_global *global, int *x)
{
	int		i;
	int		taille_baton;
	// const int	colors[] = {BORDEAU, G_FAV, BLEUF};

	i = 0;
	dda(global, &global->ray, global->player.initial_angle - degree_to_radians(map(*x) - 30)); // map prend la position de la colonne entre 0 et 1024 et rend une valeur entre -30 et 30
	taille_baton = (4000/global->ray.ray_length); // inverser, plus c'est loin plus c'est petit mais plus le rayon est long
	while (i < WIN_HEIGTH)
	{
		if (i <= WIN_HEIGTH / 2 - taille_baton / 2)
			his_mlx_pixel_put(&global->render_img, *x, i, global->window.color_ceiling_int);
		else if (i > WIN_HEIGTH / 2 + taille_baton / 2)
			his_mlx_pixel_put(&global->render_img, *x, i, global->window.color_floor_int);
		else
		{
			if (global->ray.side_hit == 'n')
				his_mlx_pixel_put(&global->render_img, *x, i, G_FAV);
			else if (global->ray.side_hit == 's')
				his_mlx_pixel_put(&global->render_img, *x, i, BORDEAU);
			else if (global->ray.side_hit == 'e')
				his_mlx_pixel_put(&global->render_img, *x, i, BLEUF);
			else if (global->ray.side_hit == 'w')
				his_mlx_pixel_put(&global->render_img, *x, i, TRUC);
		}
		++i;
	}
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
