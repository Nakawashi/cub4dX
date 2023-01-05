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

int check_player(t_map *mapinfo, int x, int y)
{
	if (ft_strchr("NSWE", mapinfo->map[y][x]) != NULL && mapinfo->pl.pos_x == -1)
	{
		mapinfo->pl.pos_x = x;
		mapinfo->pl.pos_y = y;

		if (mapinfo->map[y][x] == 'N')
			mapinfo->pl.rot = 0;
		else if (mapinfo->map[y][x] == 'S')
			mapinfo->pl.rot = 180;
		else if (mapinfo->map[y][x] == 'W')
			mapinfo->pl.rot = 90;
		else if (mapinfo->map[y][x] == 'E')
			mapinfo->pl.rot = 270;

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


int	check_map(t_map *mapinfo)
{
	int	x;
	int	y;

	y = 0;
	while (y < mapinfo->map_height)
	{
		x = 0;
		while (x < (int)ft_strlen(mapinfo->map[y]))
		{
			if (check_player(mapinfo, x, y) < 0)
				return (-2);
			x++;
		}
		y++;
	}
	if (mapinfo->pl.pos_x == -1)
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
char	**read_map(int fd)
{
	char	*line;
	char	*saved;
	t_map	mapinfo;

	mapinfo.map = NULL;
	mapinfo.map_width = 0;
	mapinfo.map_height = 0;
	mapinfo.pl.pos_x = -1;

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
			mapinfo.map_height++;
			if (ft_strchr(line, '\n') != NULL && (int)ft_strlen(line) - 1 > mapinfo.map_width)
				mapinfo.map_width = ft_strlen(line) - 1;
			else if ((int)ft_strlen(line) > mapinfo.map_width)
				mapinfo.map_width = ft_strlen(line);
		}
		free(line);
	}
	// printf("%s\n", saved);
	mapinfo.map = ft_split(saved, '\n');
	free(saved);
	printf("%d %d\n", mapinfo.map_width, mapinfo.map_height);

	// mapinfo.map_height--;
	



	check_map(&mapinfo);

	square_map(&mapinfo);
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
	return (mapinfo.map);
}
