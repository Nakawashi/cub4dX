/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:05:57 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/26 19:24:57 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

	description : remplace pixel_put qui affiche un pixel et refresh l'affichage
	ici on cree un buffer qui va stocker les pixels et les afficher en meme tps
	x and y sont les coordonnees de la fenetre.
	0, 0 est tout en haut a gauche.

	il faut dereferencer le char puis a nouveau recuperer la valeur pour
	recuperer le int casté
*/
void	his_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
	img->addr = mlx_get_data_addr(
		img->img,
		&img->bits_per_pixel,
		&img->line_length,
		&img->endian);
}

/*
	display vertical pixels
*/
void	display_rainbow(t_global *global)
{
	int			column;
	int			line;
	int			i;
	int			j;
	const int	colors[] = {0x00ff0000, 0x00ffa500, 0x00ffff00, 0x00008000, 0x000000ff, 0x004b0082, 0x00ee82ee};
	const int	sizes[] = {100, 100, 100, 100, 200, 200, 200, 300, 300, 300, 400, 400, 400, 500, 500, 500, 600, 600, 600, 700, 700, 700, 800, 800, 800, 900, 900, 900}; //19

	create_image(&global->render_img, global->window.mlx_id, WIN_WIDTH, WIN_HEIGTH);
	i = 0;
	j = 0;
	line = 0;
	while (line < WIN_WIDTH)
	{
		column = -1;
		while (column < sizes[j])//+ WIN_HEIGTH/2 + 32)
		{
			his_mlx_pixel_put(&global->render_img, line, column, colors[i/4]); // 0/4 = 0, 1/4 = 0, 2/4 = 0, 3/4 = 0, 4/4 = 1.
			++column;
			++i;
			++j;
		}
		if (i == 29)
			i = -1;
		++i;
		++line;
	}
	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id, global->render_img.img, 0, 0);
}

// void	display_rainbow(t_global *global)
// {
// 	int			column;
// 	int			line;
// 	int			i;
// 	const int	colors[] = {0x00ff0000, 0x00ffa500, 0x00ffff00, 0x00008000, 0x000000ff, 0x004b0082, 0x00ee82ee};
// 	const int	sizes[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

// 	create_image(&global->render_img, global->window.mlx_id, WIN_WIDTH, WIN_HEIGTH);
// 	i = 0;
// 	line = 0;
// 	while (line < WIN_WIDTH)
// 	{
// 		column = -1;
// 		while (column < WIN_HEIGTH)
// 		{
// 			his_mlx_pixel_put(&global->render_img, line, column, colors[i/4]);
// 			++column;
// 		}
// 		if (i == 29)
// 			i = -1;
// 		++i;
// 		++line;
// 	}
// 	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id, global->render_img.img, 0, 0);
// }
