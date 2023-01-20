/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:05:42 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/20 17:44:51 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	init t_window datas
*/
void	init_window(t_window *window)
{
	window->mlx_id = mlx_init();
	window->win_id = mlx_new_window(window->mlx_id, WIN_WIDTH, WIN_HEIGTH,
		"Half Life 3.2");
}

void	init_interface(t_global *global)
{
	init_window(&global->window);
	my_mlx_put_ceiling(global, 0, 0, BLEU);
	my_mlx_put_floor(global, 0, WIN_HEIGTH/2, JAUNE);
	global->map_datas.map = read_map("assets/map1.cub");
	if (!global->map_datas.map)
		exit (1);
	get_map_height(&global->map_datas);
}
