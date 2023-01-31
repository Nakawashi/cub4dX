/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:57:00 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/31 19:04:35 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	perform_dda(t_ray *ray)
{
	if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->side_dist.x += ray->delta_dist.x;
		ray->i_cell.x += ray->step.x;
		ray->side_dir = 'v';
		if (ray->step.x == -1)
			ray->side_hit = 'e';
		else
			ray->side_hit = 'w';
	}
	else
	{
		ray->side_dist.y += ray->delta_dist.y;
		ray->i_cell.y += ray->step.y;
		ray->side_dir = 'h';
		if (ray->step.y == -1)
			ray->side_hit = 's';
		else
			ray->side_hit = 'n';
	}
}

/*
	Digital Differential Analysis is a fast algorithm
	typically used on square grids to find which squares a line hits
	https://lodev.org/cgtutor/raycasting.html

	1. set in wich direction we are going to follow, with step value
	2. infinite loop until we find a wall
*/
t_vector2_f	dda(t_global *global, t_ray *ray, float angle)
{
	t_vector2_d cell;

	init_ray_struct(global, ray, angle);
	while (1)
	{
		perform_dda(ray);
		cell.x = ray->i_cell.x / MINI_WIDTH;
		cell.y = ray->i_cell.y / MINI_WIDTH;
		if (global->map_datas.map[cell.y][cell.x] == '1')
		{
			//Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
			if (ray->side_dir == 'v')
			{
				ray->ray_length = ray->side_dist.x - ray->delta_dist.x;
				ray->wallX = global->player.pos.y + ray->ray_length * ray->direction.y;
			}
			else
			{
				ray->ray_length = ray->side_dist.y - ray->delta_dist.y;
				ray->wallX = global->player.pos.x + ray->ray_length * ray->direction.x;
			}
			
			bresenham(global, global->player.pos, ray->i_cell, PLUM);
			return (ray->i_cell);
		}
	}
}
