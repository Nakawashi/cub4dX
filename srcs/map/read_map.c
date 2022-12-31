/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:15:07 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/31 15:50:18 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_readmap
{
	int		fd;
	char	*line;
	char	*saved;
	char	**map;
}	t_readmap;

/*
	Read the .ber map and saves it on map.map which is a 2 dimension table.
*/
char	**read_map(const char *path_to_file)
{
	t_readmap	readmap;

	readmap.map = NULL;
	readmap.fd = open(path_to_file, O_RDONLY);
	if (readmap.fd == -1)
	{
		perror("read_map: imposible d'ouvrir le fichier");
		return (NULL);
	}
	if (readmap.fd >= 0)
	{
		readmap.saved = ft_strdup_safe("");
		while (1)
		{
			readmap.line = get_next_line(readmap.fd);
			if (!readmap.line)
				break ;
			readmap.saved = ft_strjoin_free(readmap.saved, readmap.line);
			free(readmap.line);
		}
		readmap.map = ft_split(readmap.saved, '\n');
		free(readmap.saved);
	}
	close(readmap.fd);
	return (readmap.map);
}
