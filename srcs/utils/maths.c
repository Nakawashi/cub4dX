/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:54:52 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/13 12:23:08 by lgenevey         ###   ########.fr       */
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

void	dda(t_global *global)