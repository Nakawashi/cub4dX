/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:55:15 by lgenevey          #+#    #+#             */
/*   Updated: 2023/02/12 15:40:26 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	map():
	prend la position de la colonne entre 0 et 1024 et rend une valeur
	entre -30 et 30, ce qui correspond a l'angle
	taille_baton:
	inverser, plus c'est loin plus c'est petit mais plus le rayon est long

	// if (global->ray.wallX < 0.4) // V
	// if (i - wall_start < taille_baton * 0.4) // H
	get_pixel_color:
	image dans laquelle on vient prendre le pixel
	map:
	colonne du mur ou on veut dessiner
	largeur max du mur
	largeur max de la texture
*/
void	draw_column(t_global *global, int *x)
{
	int	i;
	int	taille_baton;
	int	texture;
	int	wall_start;

	dda(global, &global->ray, global->player.initial_angle - degree_to_radians(map(*x, WIN_WIDTH, 60.0) - 30));
	taille_baton = (4000/global->ray.ray_length);
	wall_start = WIN_HEIGTH / 2 - (taille_baton / 2);
	i = 0;
	while (i < WIN_HEIGTH)
	{
		if (i <= WIN_HEIGTH / 2 - taille_baton / 2)
			texture = global->window.color_ceiling_int;
		else if (i > WIN_HEIGTH / 2 + taille_baton / 2)
			texture = global->window.color_floor_int;
		else
		{
			if (global->ray.wallX > 6)
				printf("	%f\n", global->ray.wallX);
			if (global->ray.side_hit == 'n')
				texture = get_pixel_color(&global->no, (global->ray.wallX) * (TEXTURE_SIZE / MINI_WIDTH), map(i - wall_start, taille_baton, TEXTURE_SIZE));
			else if (global->ray.side_hit == 's')
				texture = get_pixel_color(&global->so, map(global->ray.wallX, MINI_WIDTH, TEXTURE_SIZE), map(i - wall_start, taille_baton, TEXTURE_SIZE));
			else if (global->ray.side_hit == 'e')
				texture = get_pixel_color(&global->ea, map(global->ray.wallX, MINI_WIDTH, TEXTURE_SIZE), map(i - wall_start, taille_baton, TEXTURE_SIZE));
			else if (global->ray.side_hit == 'w')
				texture = get_pixel_color(&global->we, map(global->ray.wallX, MINI_WIDTH, TEXTURE_SIZE), map(i - wall_start, taille_baton, TEXTURE_SIZE));
		}
		his_mlx_pixel_put(&global->render_img, *x, i, texture);
		++i;
	}
}

//texture = get_pixel_color(&global->no, map(global->ray.wallX, MINI_WIDTH, TEXTURE_SIZE), map(i - wall_start, taille_baton, TEXTURE_SIZE));
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
