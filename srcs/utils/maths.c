/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:19:45 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/13 14:38:05 by lgenevey         ###   ########.fr       */
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

// void	dda(t_global *global, t_ray *ray)
// {
// 	t_vector2_f	origin;
// 	t_vector2_f	map;
// 	t_vector2_f	direction;
// 	t_vector2_f	side_distance;
// 	t_vector2_f	delta_distance;

// 	origin = {WIN_WIDTH/2, WIN_HEIGTH/2};
// 	map = origin;
// 	direction = {global}
// }