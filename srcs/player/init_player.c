/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:30:12 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/19 22:45:42 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	get coordinates we found for the player (NSEW) and convert them into pixels
	-->then put the pixel in the middle of the square with the -2

	J : x * MINI_SIDE_SIZE - ((MINI_SIDE_SIZE/2) -2) = position x in pixels
	I : y * MINI_SIDE_SIZE - ((MINI_SIDE_SIZE/2) -2) = position x in pixels

	7 is MINI_WIDTH size for now. It's square so W and H are same.
	n is j (x) or i (y).
*/
int	coordinate_to_pixels(int n)
{
	return (n * MINI_WIDTH + (MINI_WIDTH / 2) - 2);
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
	get player's watching direction (angle)
*/
void	init_player(t_global *global, t_vector2_f pos, int color)
{
	int	i;
	int	j;

	create_image(&global->player.img, global->window.mlx_id, 4, 4);
	i = 0;
	while(i < 4)
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
