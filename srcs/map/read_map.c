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


int check_player(t_map *mapinfo, t_player *pl, int x, int y)
{
	if (ft_strchr("NSWE", mapinfo->map[y][x]) != NULL && pl->x == -1)
	{
		pl->x = x;
		pl->y = y;

		if (mapinfo->map[y][x] == 'N')
			pl->direction = 'N';
		else if (mapinfo->map[y][x] == 'S')
			pl->direction = 'S';
		else if (mapinfo->map[y][x] == 'W')
			pl->direction = 'W';
		else if (mapinfo->map[y][x] == 'E')
			pl->direction = 'W';

		mapinfo->map[y][x] = '0';
	}
	else if (ft_strchr("NSWE", mapinfo->map[y][x]) != NULL)
	{
		printf("ERROR\n Error duplicate player\n");
		return (-1);
	}
	return (0);
}

int	check_case(t_map *mapinfo, int x, int y)
{
	if (x <= 0 || y <= 0 || y >= mapinfo->map_height || x >= (int)ft_strlen(mapinfo->map[y]) - 1)
		return (-1);
	else if (x >= (int)ft_strlen(mapinfo->map[y - 1]) || x >= (int)ft_strlen(mapinfo->map[y + 1]))
	{
		return (-1);
	}
	else if (ft_strchr("01", mapinfo->map[y - 1][x]) == NULL)
		return (-1);
	else if (ft_strchr("01", mapinfo->map[y + 1][x]) == NULL)
		return (-1);
	else if (ft_strchr("01", mapinfo->map[y][x - 1]) == NULL)
		return (-1);
	else if (ft_strchr("01", mapinfo->map[y][x + 1]) == NULL)
		return (-1);

	return (0);
}


int	check_map(t_map *mapinfo, t_player *pl)
{
	int	x;
	int	y;

	y = 0;
	while (y < mapinfo->map_height)
	{
		x = 0;
		while (x < (int)ft_strlen(mapinfo->map[y]))
		{
			if (check_player(mapinfo, pl, x, y) < 0)
				return (-2);
			x++;
		}
		y++;
	}
	if (pl->x == -1)
	{
		printf("ERROR\n Error player not found\n");
		return (-1);
	}
	y = 0;
	while (y < mapinfo->map_height)
	{
		x = 0;
		while (x < (int)ft_strlen(mapinfo->map[y]))
		{
			if (ft_strchr("01 ", mapinfo->map[y][x]) == NULL)
			{
				printf("ERROR\n Error map illegal char\n");
				return (-1);
			}
			x++;
		}
		y++;
	}

	y = 0;
	while (y < mapinfo->map_height)
	{
		x = 0;
		while (x < (int)ft_strlen(mapinfo->map[y]))
		{
			if (mapinfo->map[y][x] == '0' && check_case(mapinfo, x, y) < 0)
			{
				printf("ERROR\n Error map not closed\n");
				return (-1);
			}
			x++;
		}
		y++;
	}
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

/*
	Read the .ber map and saves it on map.map which is a 2 dimension table.
	- Read the .cub until the end and return it as the map
*/
char	**read_map(t_global *global, int fd)
{
	char	*line;
	char	*saved;
	// t_map	mapinfo;

	global->map_datas.map = NULL;
	global->map_datas.map_width = 0;
	global->map_datas.map_height = 0;
	global->player.x = -1;

	saved = ft_strdup_safe("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strlen(saved) > 1 || ft_strlen(line) > 1)
		{
			if (ft_strcmp(line, "\n") == 0)
			{
				free(line);
				line = ft_strdup_safe(" \n");
			}
			saved = ft_strjoin_free(saved, line);
			global->map_datas.map_height++;

			if (ft_strchr(line, '\n') != NULL && (int)ft_strlen(line) - 1 > global->map_datas.map_width)
				global->map_datas.map_width = ft_strlen(line) - 1;

			else if ((int)ft_strlen(line) > global->map_datas.map_width)
				global->map_datas.map_width = ft_strlen(line);
		}
		free(line);
	}
	// printf("%s\n", saved);
	global->map_datas.map = ft_split(saved, '\n');
	free(saved);
	printf("%d %d\n", global->map_datas.map_width, global->map_datas.map_height);

	// mapinfo.map_height--;
	



	check_map(&global->map_datas, &global->player);

	square_map(&global->map_datas);
	// for (int i = 0; i < mapinfo.map_height; i++)
	// {
	// 	for (int j = 0; j < (int)ft_strlen(mapinfo.map[i]); j++)
	// 	// for (int j = 0; j < mapinfo.map_width; j++)
	// 	{
	// 		printf("%c", mapinfo.map[i][j]);
	// 	}
	// 	printf("\n");

	// }
	// return (NULL);
	return (global->map_datas.map);
}
