/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:57:00 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/31 15:56:38 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	t_vector2_f step; // either 1 or -1
	t_vector2_f	delta_distance;

	ray->impact_cell = global->player.position;
	ray->direction.x = cos(angle);
	ray->direction.y = sin(angle);
	delta_distance.x = get_delta_distance(ray->direction.x);
	delta_distance.y = get_delta_distance(ray->direction.y);
	if (ray->direction.x < 0)
	{
		step.x = -1;
		ray->side_dist.x = (global->player.position.x - ray->impact_cell.x) * delta_distance.x; // Calculating X gap to the nearest integer coordinate
	}
	else
	{
		step.x = 1;
		ray->side_dist.x = (ray->impact_cell.x + 1.0f - global->player.position.x) * delta_distance.x;
	}
	if (ray->direction.y < 0)
	{
		step.y = -1;
		ray->side_dist.y = (global->player.position.y - ray->impact_cell.y) * delta_distance.y; // Calculating Y gap to the nearest integer coordinate
	}
	else
	{
		step.y = 1;
		ray->side_dist.y = (ray->impact_cell.y + 1.0f - global->player.position.y) * delta_distance.y;
	}
	while (1)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += delta_distance.x;
			ray->impact_cell.x += step.x;
			ray->side_dir = 'v';
			if (step.x == -1)
				ray->side_hit = 'e';
			else
				ray->side_hit = 'w';
		}
		else
		{
			ray->side_dist.y += delta_distance.y;
			ray->impact_cell.y += step.y;
			ray->side_dir = 'h';
			if (step.y == -1)
				ray->side_hit = 's';
			else
				ray->side_hit = 'n';
		}
		cell.x = ray->impact_cell.x / MINI_WIDTH;
		cell.y = ray->impact_cell.y / MINI_WIDTH;
		if (global->map_datas.map[cell.y][cell.x] == '1')
		{
			//Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
			if (ray->side_dir == 'v')
			{
				printf("ray->side_dir : [%c]\n", ray->side_dir);
				ray->ray_length = ray->side_dist.x - delta_distance.x;
				printf("ray->ray_length : [%f]\n", ray->ray_length);
				ray->wallX = global->player.position.y + ray->ray_length * ray->direction.y;
			}
			else
			{
				printf("ray->side_dir : [%c]\n", ray->side_dir);
				ray->ray_length = ray->side_dist.y - delta_distance.y;
				printf("ray->ray_length : [%f]\n\n", ray->ray_length);
				ray->wallX = global->player.position.x + ray->ray_length * ray->direction.x;
			}
			bresenham(global, global->player.position, ray->impact_cell, PLUM);
			return (ray->impact_cell);
		}
	}
}
