/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:57:00 by lgenevey          #+#    #+#             */
/*   Updated: 2023/02/14 17:31:24 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ray_struct(t_global *global, t_ray *ray, float angle);
static void	init_side_dist(t_ray *ray);
static void	perform_dda(t_ray *ray);
static void	init_datas(t_global *g, t_ray *r, float *angle);

/*
	Digital Differential Analysis is a fast algorithm
	typically used on square grids to find which squares a line hits
	https://lodev.org/cgtutor/raycasting.html

	1. set in wich direction we are going to follow, with step value
	2. infinite loop until we find a wall
*/
int	dda(t_global *g, t_ray *r, float angle)
{
	t_vector2_d	cell;

	init_ray_struct(g, r, angle);
	while (1)
	{
		perform_dda(r);
		cell.x = r->icell.x / MINI_WIDTH;
		cell.y = r->icell.y / MINI_WIDTH;
		if (g->map_datas.map[cell.y][cell.x] == '1')
		{
			init_datas(g, r, &angle);
			bresenham(g, g->player.pos, r->icell, PLUM);
			return (0);
		}
	}
	return (1);
}

static void	perform_dda(t_ray *ray)
{
	if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->side_dist.x += ray->delta_dist.x;
		ray->icell.x += ray->step.x;
		ray->side_dir = 'v';
		if (ray->step.x == -1)
			ray->side_hit = 'e';
		else
			ray->side_hit = 'w';
	}
	else
	{
		ray->side_dist.y += ray->delta_dist.y;
		ray->icell.y += ray->step.y;
		ray->side_dir = 'h';
		if (ray->step.y == -1)
			ray->side_hit = 's';
		else
			ray->side_hit = 'n';
	}
}

static void	init_datas(t_global *g, t_ray *r, float *angle)
{
	if (r->side_dir == 'v')
	{
		r->wallx = fmod(g->player.pos.y + r->ray_len * r->dir.y, 8);
		r->ray_len = (r->side_dist.x - r->delta_dist.x)
			* cos(*angle - g->player.initial_angle);
	}
	else
	{
		r->wallx = fmod(g->player.pos.x + r->ray_len * r->dir.x, 8);
		r->ray_len = (r->side_dist.y - r->delta_dist.y)
			* cos(*angle - g->player.initial_angle);
	}
}

void	init_ray_struct(t_global *global, t_ray *ray, float angle)
{
	ray->player = global->player;
	ray->icell = global->player.pos;
	ray->dir.x = cos(angle);
	ray->dir.y = sin(angle);
	ray->delta_dist.x = get_delta_distance(ray->dir.x);
	ray->delta_dist.y = get_delta_distance(ray->dir.y);
	init_side_dist(ray);
}

/*
	ray->direction.x < 0 : look at the east (v)
	ray->direction.y < 0 : look at the south (h)
*/
void	init_side_dist(t_ray *r)
{
	if (r->dir.x < 0)
	{
		r->step.x = -1;
		r->side_dist.x
			= (r->player.pos.x - (int)r->icell.x) * r->delta_dist.x;
	}
	else
	{
		r->step.x = 1;
		r->side_dist.x
			= ((int)r->icell.x + 1.0f - r->player.pos.x) * r->delta_dist.x;
	}
	if (r->dir.y < 0)
	{
		r->step.y = -1;
		r->side_dist.y
			= (r->player.pos.y - (int)r->icell.y) * r->delta_dist.y;
	}
	else
	{
		r->step.y = 1;
		r->side_dist.y
			= ((int)r->icell.y + 1.0f - r->player.pos.y) * r->delta_dist.y;
	}
}
