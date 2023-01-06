/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:25:34 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/06 19:39:02 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	map_width:
		line length, we have to count after, for each line bc not rectangle
	map_height:
		nb of rows, counted here
*/
void	init_map(t_map *map)
{
	int	i;

	map->map_width = 0;
	i = 0;
	while (map->map[i])
		++i;
	map->map_height = i;
}