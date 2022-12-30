/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:05:42 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/30 16:12:37 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3d.h"

static void	init_window_size(t_window *window)
{
	// window->win_width = 1920;
	// window->win_height = 1080;
	window->win_width = 1024;
	window->win_height = 512;
}

/*
	init t_window datas
*/
void	init_window(t_window *window)
{
	window->mlx_id = mlx_init();
	init_window_size(window);
	window->win_id = mlx_new_window(
		window->mlx_id,
		window->win_width,
		window->win_height,
		"WolfenStein4dX"
	);
}

void	display_ground_and_ceiling(char *ground, char *ceiling)
{
	ground = "grey";
	ceiling = "blue";
}