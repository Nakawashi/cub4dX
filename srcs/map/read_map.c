/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:15:07 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/08 14:42:47 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	read_map_line(t_global *global, char **saved, char **line);

/*
	Read the .ber map and saves it on map.map which is a 2 dimension table.
	- Read the .cub until the end and return it as the map
*/
int	read_map(t_global *global, int fd)
{
	char	*line;
	char	*saved;

	saved = ft_strdup_safe("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strlen(saved) > 1 || ft_strlen(line) > 1)
		{
			read_map_line(global, &saved, &line);
			global->map_datas.map_height++;
		}
		free(line);
	}
	global->map_datas.map = ft_split(saved, '\n');
	free(saved);
	return (0);
}

static int	read_map_line(t_global *global, char **saved, char **line)
{
	if (ft_strcmp(*line, "\n") == 0)
	{
		free(*line);
		*line = ft_strdup_safe(" \n");
	}
	*saved = ft_strjoin_free(*saved, *line);
	if (ft_strchr(*line, '\n') != NULL
		&& (int)ft_strlen(*line) - 1 > global->map_datas.map_width)
	{
		global->map_datas.map_width = ft_strlen(*line) - 1;
	}
	else if ((int)ft_strlen(*line) > global->map_datas.map_width)
	{
		global->map_datas.map_width = ft_strlen(*line);
	}
	return (0);
}

int	check_map(t_map *mapinfo, t_player *pl)
{
	if (check_player(mapinfo, pl) < 0)
		return (-2);
	if (check_illegal_chars(mapinfo) < 0)
		return (-2);
	if (check_cases(mapinfo) < 0)
		return (-2);
	return (0);
}

int	square_map(t_map *mapinfo)
{
	int		i;
	char	*newline;

	i = 0;
	while (i < mapinfo->map_height)
	{
		if ((int)ft_strlen(mapinfo->map[i]) < mapinfo->map_width)
		{
			newline = ft_calloc(mapinfo->map_width + 1, sizeof(char));
			if (!newline)
			{
				printf("ERROR\n Malloc error\n");
				return (-1);
			}
			ft_memset(newline, '1', mapinfo->map_width);
			ft_memcpy(newline, mapinfo->map[i], ft_strlen(mapinfo->map[i]));
			free(mapinfo->map[i]);
			mapinfo->map[i] = newline;
		}
		while (ft_strchr(mapinfo->map[i], ' ') != NULL)
			*(ft_strchr(mapinfo->map[i], ' ')) = '1';
		i++;
	}
	return (0);
}
