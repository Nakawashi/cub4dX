/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:30:12 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/10 18:27:28 by lgenevey         ###   ########.fr       */
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
	return (n * MINI_WIDTH + (MINI_WIDTH/2) - 2);
}

/*
	Image creation
	First time we display the player on screen
*/
void	init_player(t_global *global, int x, int y, int color)
{
	int	i;
	int	j;

	create_image(&global->player.player_img, global->window.mlx_id, 4, 4);
	i = 0;
	while(i < 4)
	{
		j = 0;
		while (j < 4)
		{
			his_mlx_pixel_put(&global->player.player_img, j, i, color);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id,
		global->player.player_img.img, x, y);
}

/*
	Raison de 4: 1 pixel c'etait trop petit voila. Ne fonctionne que si
	la taille des cotes des carres de la minimap est paire
*/
void	display_player(t_global *global, int x, int y, int color)
{
	int			i;
	int			j;

	i = 0;
	while(i < 4)
	{
		j = 0;
		while (j < 4)
		{
			his_mlx_pixel_put(&global->player.player_img, j, i, color);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(global->window.mlx_id, global->window.win_id,
		global->player.player_img.img, x, y);
}