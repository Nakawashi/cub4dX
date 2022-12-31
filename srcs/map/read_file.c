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
	fd = 789;
	printf("fd : %d\n", fd);
	fd = open(path_to_file, O_RDONLY);
	printf("fd : %d\n", fd);
	printf("path to file : %s\n", path_to_file);
	if (fd == -1)
	{
		perror("read_map: imposible d'ouvrir le fichier");
		return (NULL);
	}
	if (fd >= 0)
	{
		
		map = read_map(fd);
	}
	close(fd);
	return (map);
}
