/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:15:43 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/31 17:24:57 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray_struct(t_global *global, t_ray *ray, float angle)
{
	ray->player = global->player;
	ray->i_cell = global->player.pos;
	ray->direction.x = cos(angle);
	ray->direction.y = sin(angle);
	ray->delta_dist.x = get_delta_distance(ray->direction.x);
	ray->delta_dist.y = get_delta_distance(ray->direction.y);
	init_side_dist(ray);
}

void	init_side_dist(t_ray *ray)
{
	if (ray->direction.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x
			= (ray->player.pos.x - ray->i_cell.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x
			= (ray->i_cell.x + 1.0f - ray->player.pos.x) * ray->delta_dist.x;
	}
	if (ray->direction.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y
			= (ray->player.pos.y - ray->i_cell.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y
			= (ray->i_cell.y + 1.0f - ray->player.pos.y) * ray->delta_dist.y;
	}
}
