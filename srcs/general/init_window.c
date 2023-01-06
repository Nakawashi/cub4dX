/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:05:42 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/06 18:07:30 by lgenevey         ###   ########.fr       */
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
