/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:56:28 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/13 12:09:28 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	@arguments
	char direction and float angle: init t_player
	@description
	Indique dans quelle direction le joueur avancera sur la minimap
*/
void	player_direction(char direction, float angle)
{
	if (direction == 'N')
		angle = degree_to_radians(-90);
	if (direction == 'W')
		angle = degree_to_radians(180);
	if (direction == 'E')
		angle = degree_to_radians(0);
	if (direction == 'S')
		angle = degree_to_radians(90);
}