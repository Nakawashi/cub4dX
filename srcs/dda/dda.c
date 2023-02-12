/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:57:00 by lgenevey          #+#    #+#             */
/*   Updated: 2023/02/10 16:50:59 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ray_struct(t_global *global, t_ray *ray, float angle);
static void	init_side_dist(t_ray *ray);
static void	perform_dda(t_ray *ray);

/*
	Digital Differential Analysis is a fast algorithm
	typically used on square grids to find which squares a line hits
	https://lodev.org/cgtutor/raycasting.html

	1. set in wich direction we are going to follow, with step value
	2. infinite loop until we find a wall
*/
int	dda(t_global *global, t_ray *ray, float angle)
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
			if (ray->side_dir == 'v')
			{
				ray->wallX = fmod(global->player.pos.y + ray->ray_length * ray->direction.y, 8);
				ray->ray_length = (ray->side_dist.x - ray->delta_dist.x) * cos(angle - global->player.initial_angle);
			}
			else
			{
				ray->wallX = fmod(global->player.pos.x + ray->ray_length * ray->direction.x, 8);
				ray->ray_length = (ray->side_dist.y - ray->delta_dist.y) * cos(angle - global->player.initial_angle);
			}

			bresenham(global, global->player.pos, ray->i_cell, PLUM);
			return (0);
		}
	}
	return (1);
}

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
