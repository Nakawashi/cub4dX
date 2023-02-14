/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:30:12 by lgenevey          #+#    #+#             */
/*   Updated: 2023/02/14 11:11:23 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	get coordinates we found for the player (NSEW) and convert them into pixels
	-->then put the pixel in the middle of the square with the -2

	J : x * MINI_SIDE_SIZE - ((MINI_SIDE_SIZE/2) -2) = position x in pixels
	I : y * MINI_SIDE_SIZE - ((MINI_SIDE_SIZE/2) -2) = position x in pixels

	8 is MINI_WIDTH size for now. It's square so W and H are same.
	n is j (x) or i (y).
*/
// int	coordinate_to_pixels(int n)
// {
// 	return (n * MINI_WIDTH + (MINI_WIDTH / 2) - 2);
// }
float	coordinate_to_pixels(int n)
{
	float	res;

	res = (float)n * MINI_WIDTH + (MINI_WIDTH / 2) - 2;
	return (res);
}

int	pixels_to_coordinate(float n)
{
	int	res;

	res = n / MINI_HEIGHT;
	return (res);
}

/*
	@arguments
	t_global *global : can access to many datas
	int x and int y : coordinates where the image is printed
	int color : color of the image
	@description
	get player's coordinates
	Creation of the player's image
	Print it on the screen at those coordinates
	get player's watching direction (initial_angle)
*/
void	init_player(t_global *global, t_vector2_f pos, int color)
{
	int	i;
	int	j;

	create_image(&global->player.img, global->window.mlx_id, 4, 4);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			his_mlx_pixel_put(&global->player.img, j, i, color);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id,
		global->player.img.img, pos.x, pos.y);
}
