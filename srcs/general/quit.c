/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:20:37 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/08 17:15:07 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3d.h"

static void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static int	clean(t_global *global)
{
	free_map(global->map_datas.map);
	mlx_destroy_window(global->window.mlx_id, global->window.win_id);
	exit(0);
}

/*
	get key event
	display nb move in window
*/
static int	key_hook(int keycode, t_global *global)
{
	if (keycode == EVENT_KEY_ESC)
		clean(global);
	return (0);
}

/*
	mlx_key_hook : handle ESC, W, A, S, D
	mlx_hook : handle quit by closing window
*/
void	quit_program(t_global *global)
{
	mlx_key_hook(global->window.win_id, key_hook, global);
	mlx_hook(global->window.win_id, EVENT_KEY_EXIT, 0, clean, global);
}