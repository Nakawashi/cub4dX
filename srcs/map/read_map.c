/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:15:07 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/31 14:08:48 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	Read the .ber map and saves it on map.map which is a 2 dimension table.
*/
char	**read_map(const char *path_to_file)
{
	int		fd;
	char	*line;
	char	*saved;
	char	**map;

	map = NULL;
	fd = open(path_to_file, O_RDONLY);
	printf("path to file : %s\n", path_to_file);
	if (fd == -1)
	{
		perror("read_map: imposible d'ouvrir le fichier");
		return (NULL);
	}
	if (fd >= 0)
	{
		saved = ft_strdup_safe("");
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break ;
			saved = ft_strjoin_free(saved, line);
			free(line);
		}
		map = ft_split(saved, '\n');
		free(saved);
	}
	close(fd);
	return (map);
}
