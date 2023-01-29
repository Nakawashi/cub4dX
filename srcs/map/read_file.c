/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:15:07 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/31 13:35:38 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_filename(const char *path);

/*
	Read the .ber map and saves it on map.map which is a 2 dimension table.
*/
int	read_file(t_global *global, const char *path_to_file)
{
	int		fd;

	if (check_filename(path_to_file) < 0)
		return (-2);
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
	return (0);
}


static int	check_filename(const char *path)
{
	if (ft_strlen(path) >= ft_strlen(".cub"))
	{
		return (ft_strcmp(path + (ft_strlen(path) - 4), ".cub"));
	}
	return (-1);
}
