/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:20:37 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/09 20:35:50 by lgenevey         ###   ########.fr       */
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

/*
	penser a delete toutes les images (voir la struct au besoin)
	free la map
	la window
*/
int	clean(t_global *global)
{
	free_map(global->map_datas.map);
	mlx_destroy_window(global->window.mlx_id, global->window.win_id);
	exit(0);
}
