/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:15:07 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/31 13:35:38 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		store_color(int *dest, char **splited);
static int		process_color(int *dest, char *r, char *g, char *b);
static size_t	count_chars(char *line, char search);

int	parse_colors(t_global *global)
{
	char	**splited;

	if (count_chars(global->window.color_ceiling_hexa, ',') != 2)
	{
		printf("ERROR\n Error color ceiling invalid\n");
		return (-1);
	}
	if (count_chars(global->window.color_floor_hexa, ',') != 2)
	{
		printf("ERROR\n Error color floor invalid\n");
		return (-1);
	}
	splited = ft_split(global->window.color_ceiling_hexa, ',');
	if (store_color(&global->window.color_ceiling_int, splited) < 0)
		return (-2);
	splited = ft_split(global->window.color_floor_hexa, ',');
	if (store_color(&global->window.color_floor_int, splited) < 0)
		return (-2);
	return (0);
}

static int	store_color(int *dest, char **splited)
{
	if (splited == NULL)
	{
		printf("ERROR\n Malloc error\n");
		return (-1);
	}
	if (ft_tab_length(splited) != 3 || ft_strlen(splited[0]) == 0
		|| ft_strlen(splited[1]) == 0 || ft_strlen(splited[2]) == 0)
	{
		printf("ERROR\n Error color length\n");
		return (-1);
	}
	if (process_color(dest, splited[0], splited[1], splited[2]) < 0)
	{
		ft_free_ppointer(splited);
		printf("ERROR\n Error color invalid\n");
		return (-1);
	}
	ft_free_ppointer(splited);
	return (0);
}

static int	process_color(int *dest, char *r, char *g, char *b)
{
	int	tmp;

	if (r == NULL || g == NULL || b == NULL)
	{
		printf("ERROR\n Malloc error\n");
		return (-1);
	}
	tmp = ft_atoi(r);
	if (tmp < 0 || tmp >= 256)
		return (-1);
	*dest = tmp;
	*dest = *dest << 8;
	tmp = ft_atoi(g);
	if (tmp < 0 || tmp >= 256)
		return (-1);
	*dest = *dest | tmp;
	*dest = *dest << 8;
	tmp = ft_atoi(b);
	if (tmp < 0 || tmp >= 256)
		return (-1);
	*dest = *dest | tmp;
	return (0);
}

static size_t	count_chars(char *line, char search)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (i < ft_strlen(line))
	{
		if (line[i] == search)
			count++;
		i++;
	}
	return (count);
}
