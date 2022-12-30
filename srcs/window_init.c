/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:05:42 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/30 14:11:32 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

static void	get_window_size(t_window *window)
{
	window->win_width = 1920;
	window->win_height = 1080;
}

void	init_window(t_window *window)
{
	window->mlx_id = mlx_init();
	get_window_size(window);
	window->win_id = mlx_new_window(
		window->mlx_id,
		window->win_width,
		window->win_height,
		"WolfenStein4dX"
	);
}