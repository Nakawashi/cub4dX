/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:05:57 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/29 12:39:07 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

	description : remplace pixel_put qui affiche un pixel et refresh l'affichage
	ici on cree un buffer qui va stocker les pixels et les afficher en meme tps
	x and y sont les coordonnees du pixel par rapport a la fenetre
	0, 0 est tout en haut a gauche.

	il faut dereferencer le char puis a nouveau recuperer la valeur pour
	recuperer le int casté

	img->addr : on met le pixel de telle couleur a cet index du tableau
*/
void	his_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	if (x < 0 || y < 0 || x > img->img_width || y > img->img_height)
		return ;
	img->addr[y * img->line_length + x] = color;
}

void	init_img_struct(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->texture_path = NULL;
	img->img_width = 0;
	img->img_height = 0;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
}

void	create_image(t_img *img, t_window *mlx_id, int width, int height)
{
	init_img_struct(img);
	img->img = mlx_new_image(mlx_id, width, height);
	img->img_width = width;
	img->img_height = height;
	img->addr = (int *)mlx_get_data_addr(
		img->img,
		&img->bits_per_pixel,
		&img->line_length,
		&img->endian);
	img->line_length /= 4;
}

void	display_rainbow(t_global *global)
{
	int			column;
	int			line;
	int			i;
	const int	colors[] = {BORDEAU, G_FAV, BLEUF};
	// const int	sizes[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

	create_image(&global->render_img, global->window.mlx_id, WIN_WIDTH, WIN_HEIGTH);
	i = 0;
	line = 0;
	while (line < WIN_WIDTH)
	{
		column = 0;
		while (column < WIN_HEIGTH)
		{
			if (column <= 250)
				his_mlx_pixel_put(&global->render_img, line, column, TRANSP);//meme taille que la couleur
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
	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id, global->render_img.img, 0, 0);
}
