/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:15:07 by lgenevey          #+#    #+#             */
/*   Updated: 2023/02/14 17:13:53 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	after_parse(t_global *global);

/*
	Read the .ber map and saves it on map.map which is a 2 dimension table.
*/
int	read_file(t_global *global, char *path_to_file)
{
	int		fd;

	fd = open(path_to_file, O_RDONLY);
	if (fd == -1)
	{
		perror("read_map: imposible d'ouvrir le fichier");
		return (-1);
	}
	if (fd >= 0)
	{
		if (read_args(global, fd) < 0)
			return (-2);
		if (read_map(global, fd) < 0)
			return (-2);
		if (check_map(&global->map_datas, &global->player) < 0)
			return (-2);
		if (square_map(&global->map_datas) < 0)
			return (-2);
	}
	close(fd);
	if (after_parse(global) < 0)
		return (-2);
	return (0);
}

static int	after_parse(t_global *g)
{
	if (open_image(&g->no, g->window.mlx_id, g->no.texture_path) < 0)
		return (-2);
	if (open_image(&g->so, g->window.mlx_id, g->so.texture_path) < 0)
		return (-2);
	if (open_image(&g->we, g->window.mlx_id, g->we.texture_path) < 0)
		return (-2);
	if (open_image(&g->ea, g->window.mlx_id, g->ea.texture_path) < 0)
		return (-2);
	if (parse_colors(g) < 0)
		return (-2);
	return (0);
}

int	check_filename(const char *path)
{
	if (ft_strlen(path) >= ft_strlen(".cub"))
	{
		return (ft_strcmp(path + (ft_strlen(path) - 4), ".cub"));
	}
	return (-1);
}
