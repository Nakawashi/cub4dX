/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:15:07 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/30 16:19:40 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3d.h"
#include "get_next_line/get_next_line.h"

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
	if (fd == -1)
		return (NULL);
	if (fd >= 0)
	{
		saved = ft_strdup("");
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