/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:20:37 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/30 16:12:47 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3d.h"

static int	clean(t_window *window)
{
	mlx_destroy_window(window->mlx_id, window->win_id);
	exit(0);
}

/*
	get key event
	display nb move in window
*/
static int	key_hook(int keycode, t_window *window)
{
	if (keycode == EVENT_KEY_ESC)
		clean(window);
	return (0);
}

/*
	mlx_key_hook : handle ESC, W, A, S, D
	mlx_hook : handle quit by closing window
*/
void	quit_program(t_window *window)
{
	mlx_key_hook(window->win_id, key_hook, window);
	mlx_hook(window->win_id, EVENT_KEY_EXIT, 0, clean, window);
}