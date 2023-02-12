/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:19:45 by lgenevey          #+#    #+#             */
/*   Updated: 2023/02/10 17:26:45 by lgenevey         ###   ########.fr       */
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

/*
	Re-maps a number from one range to another.
	First range : widths pixels
	Second range : FOV
	map(value, fromLow, fromHigh, toLow, toHigh)
	value: the number to map.
	fromLow: the lower bound of the value’s current range.
	fromHigh: the upper bound of the value’s current range.
	toLow: the lower bound of the value’s target range.
	toHigh: the upper bound of the value’s target range.
	https://www.arduino.cc/reference/en/language/functions/math/map/
	x		:	ou je suis actuellement entre 0 et largeur de fenetre
	in_min	:	colonne min, 0
	in_max	:	colonne max, WIN_WIDTH
	out_min	:	min range du FOV, 0 ou -30
	out_max	:	max range du FOV, 60 ou 30
	retourne un nombre entre 0 et 60 ici
*/
// float	map(long x, long in_min, long in_max, long out_min, long out_max)
// {
// 	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
// }
float	map(long pos, long in_max, long out_min)
{
	return ((pos - 0.0) * (0.0 - out_min) / (in_max - 0.0) + out_min);
}

