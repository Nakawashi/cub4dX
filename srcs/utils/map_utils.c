/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:25:34 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/09 15:41:16 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	map_width:
		line length, we have to count after, for each line bc not rectangle
	map_height:
		nb of rows, counted here
*/
void	get_map_height(t_map *map)
{
	int	i;

	if (!map->map || !*map->map)
	{
		printf("Impossible d'acceder a la map et donc d'obtenir la \
			largeur ou hauteur de la map\n");
		return ;
	}
	i = 0;
	map->map_width = ft_strlen(map->map[i]);
	while (map->map[i])
		++i;
	map->map_height = i;
}

/*

*/