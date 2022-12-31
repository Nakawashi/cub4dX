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
	- Read the .cub until the end and return it as the map
*/
char	**read_map(int fd)
{
	char	*line;
	char	*saved;
	char	**map;

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

	return (map);
}
