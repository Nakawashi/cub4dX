/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:15:07 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/31 13:35:38 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	Read the .ber map and saves it on map.map which is a 2 dimension table.
*/
char	**read_file(const char *path_to_file)
{
	int		fd;
	char	**map;

	map = NULL;
	fd = open(path_to_file, O_RDONLY);
	if (fd == -1)
	{
		perror("read_map: imposible d'ouvrir le fichier");
		return (NULL);
	}
	if (fd >= 0)
	{
		read_args(fd);
		map = read_map(fd);
	}
	close(fd);
	exit(0);
	return (map);
}
