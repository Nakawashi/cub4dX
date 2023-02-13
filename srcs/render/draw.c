/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:55:15 by lgenevey          #+#    #+#             */
/*   Updated: 2023/02/13 21:39:45 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_textures(t_global *g, int *i, int *wall_start)
{
	if (g->ray.side_hit == 'n')
		g->texture = get_pixel_color(&g->no,
				TEXTURE_SIZE - (g->ray.wallX) * (TEXTURE_SIZE / MINI_WIDTH),
				map(g->ray.stick_size - (*i - *wall_start),
					g->ray.stick_size,
					TEXTURE_SIZE));
	else if (g->ray.side_hit == 's')
		g->texture = get_pixel_color(&g->so,
				(g->ray.wallX) * (TEXTURE_SIZE / MINI_WIDTH),
				map(g->ray.stick_size - (*i - *wall_start),
					g->ray.stick_size,
					TEXTURE_SIZE));
	else if (g->ray.side_hit == 'e')
				g->texture = get_pixel_color(&g->ea,
				TEXTURE_SIZE - (g->ray.wallX) * (TEXTURE_SIZE / MINI_WIDTH),
				map(g->ray.stick_size - (*i - *wall_start),
					g->ray.stick_size,
					TEXTURE_SIZE));
	else if (g->ray.side_hit == 'w')
		g->texture = get_pixel_color(&g->we,
				(g->ray.wallX) * (TEXTURE_SIZE / MINI_WIDTH),
				map(g->ray.stick_size - (*i - *wall_start),
					g->ray.stick_size,
					TEXTURE_SIZE));
}

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
static void	draw_column(t_global *g, int *x)
{
	int		i;
	int		wall_start;

	dda(g,
		&g->ray,
		g->player.initial_angle - deg_to_rad(map(*x, WIN_WIDTH, 60.0) - 30));
	g->ray.stick_size = (4000.0 / g->ray.ray_len);
	wall_start = WIN_HEIGTH / 2 - (g->ray.stick_size / 2);
	i = 0;
	while (i < WIN_HEIGTH)
	{
		if (i <= WIN_HEIGTH / 2 - g->ray.stick_size / 2)
			g->texture = g->window.color_ceiling_int;
		else if (i > WIN_HEIGTH / 2 + g->ray.stick_size / 2)
			g->texture = g->window.color_floor_int;
		else
			get_textures(g, &i, &wall_start);
		his_mlx_pixel_put(&g->render_img, *x, i, g->texture);
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
	create_image(&global->render_img,
		global->window.mlx_id,
		WIN_WIDTH,
		WIN_HEIGTH);
	draw_rainbow(global);
	mlx_put_image_to_window(global->window.mlx_id,
		global->window.win_id,
		global->render_img.img, 0, 0);
}
