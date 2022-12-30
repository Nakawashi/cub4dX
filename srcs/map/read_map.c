/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:15:07 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/30 18:27:31 by lgenevey         ###   ########.fr       */
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
		// printf("fd == -1");
		perror("imposible d'ouvrir le fichier");
		return (NULL);
	}
	if (fd >= 0)
	{
		printf("fichier ouvert OK");
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
		printf("%s", map[0]);
		free(saved);
	}
	close(fd);
	return (map);
}
