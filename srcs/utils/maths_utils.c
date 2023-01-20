/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:19:45 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/19 23:58:08 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	degree_to_radians(float degree)
{
	return (degree * M_PI / 180.0);
}

float	radians_to_degrees(float radian)
{
	return (radian / (M_PI / 180.0));
}

t_vector2_d	ftoi(t_vector2_f positions)
{
	t_vector2_d	destination;

	destination.x = (int)positions.x;
	destination.y = (int)positions.y;
	return (destination);
}

float	get_delta_distance(float direction)
{
	float	delta_distance;

	if (direction == 0)
		delta_distance = 1e30;
	else
		delta_distance = fabs(1.0f / direction);
	return (delta_distance);
}
