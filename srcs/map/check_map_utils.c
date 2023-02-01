#include "cub3d.h"

static int	save_player(t_map *mapinfo, t_player *pl, int x, int y);
static int	check_case_borders(t_map *mapinfo, int x, int y);

int	check_player(t_map *mapinfo, t_player *pl)
{
	int	x;
	int	y;

	y = 0;
	while (y < mapinfo->map_height)
	{
		x = 0;
		while (x < (int)ft_strlen(mapinfo->map[y]))
		{
			if (save_player(mapinfo, pl, x, y) < 0)
				return (-2);
			x++;
		}
		y++;
	}
	if (pl->pos.x == -1)
	{
		printf("ERROR\n Error player not found\n");
		return (-1);
	}
	return (0);
}

int	check_illegal_chars(t_map *mapinfo)
{
	int	x;
	int	y;

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
	return (0);
}

int	check_cases(t_map *mapinfo)
{
	int	x;
	int	y;

	y = 0;
	while (y < mapinfo->map_height)
	{
		x = 0;
		while (x < (int)ft_strlen(mapinfo->map[y]))
		{
			if (mapinfo->map[y][x] == '0'
					&& check_case_borders(mapinfo, x, y) < 0)
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

static int	save_player(t_map *mapinfo, t_player *pl, int x, int y)
{
	if (ft_strchr("NSWE", mapinfo->map[y][x]) != NULL && pl->pos.x == -1)
	{
		pl->pos.x = coordinate_to_pixels(x);
		pl->pos.y = coordinate_to_pixels(y);
		if (mapinfo->map[y][x] == 'N')
			pl->initial_angle = degree_to_radians(-90);
		else if (mapinfo->map[y][x] == 'S')
			pl->initial_angle = degree_to_radians(90);
		else if (mapinfo->map[y][x] == 'W')
			pl->initial_angle = degree_to_radians(180);
		else if (mapinfo->map[y][x] == 'E')
			pl->initial_angle = degree_to_radians(0);
		mapinfo->map[y][x] = '0';
	}
	else if (ft_strchr("NSWE", mapinfo->map[y][x]) != NULL)
	{
		printf("ERROR\n Error duplicate player\n");
		return (-1);
	}
	return (0);
}

static int	check_case_borders(t_map *mapinfo, int x, int y)
{
	if (x <= 0 || y <= 0 || y >= mapinfo->map_height
		|| x >= (int)ft_strlen(mapinfo->map[y]) - 1)
		return (-1);
	else if (x >= (int)ft_strlen(mapinfo->map[y - 1])
		|| x >= (int)ft_strlen(mapinfo->map[y + 1]))
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
