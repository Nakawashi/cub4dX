/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sqare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:08:37 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/07 13:21:02 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

enum e_minimap
{
	MINI_FLOOR = 0,
	MINI_WALL,
	MINI_DOOR,
	MINI_PLAYER,
};

typedef struct s_minimap
{
	t_img	*floor;
	t_img	*wall;
	int		mini_height;
	int		mini_width;
}	t_minimap;

void	create_sq_image(t_img *img, t_window *mlx_id)
{
	init_img_struct(img);
	img->line_length = WIN_WIDTH;
	img->img = mlx_new_image(mlx_id, WIN_WIDTH, WIN_HEIGTH/2);
	img->addr = mlx_get_data_addr(
		img->img,
		&img->bits_per_pixel,
		&img->line_length,
		&img->endian);
}

/*
	draw colored pixel (floor)
	careful: i and j build the image (line per line)
	x and y are position where to start to prin, in the window
*/
void	my_mlx_put_sqare(t_global *global, int x, int y, int color)
{
	int	i;
	int	j;

	create_bg_image(&global->floor_img, global->window.mlx_id);
	i = 0;
	while(i < WIN_HEIGTH/2)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			my_mlx_pixel_put(&global->floor_img, j, i, color);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id,
		global->floor_img.img, x, y);
}