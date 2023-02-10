/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:35:01 by lgenevey          #+#    #+#             */
/*   Updated: 2023/02/07 16:43:24 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	xi;
	int	yi;
	int	d;
	int	x;
	int	cst1;
	int	cst2;
	int	y;
}	t_bresenham;

/*
	plot line high (y)
*/
static void
	draw_y(t_global *global, t_vector2_f p1, t_vector2_f dest, int color)
{
	t_bresenham	datas;

	datas.dx = dest.x - p1.x;
	datas.dy = dest.y - p1.y;
	datas.xi = 1;
	if (datas.dx < 0)
	{
		datas.xi = -1;
		datas.dx = -datas.dx;
	}
	datas.d = 2 * datas.dx - datas.dy;
	datas.x = p1.x;
	datas.cst1 = 2 * (datas.dx - datas.dy);
	datas.cst2 = 2 * datas.dx;
	datas.y = p1.y;
	while (datas.y < dest.y)
	{
		his_mlx_pixel_put(&global->minimap, datas.x, datas.y, color);
		if (datas.d > 0)
		{
			datas.x += datas.xi;
			datas.d += datas.cst1;
		}
		else
			datas.d += datas.cst2;
		++datas.y;
	}
}

static void
	draw_x(t_global *global, t_vector2_f p1, t_vector2_f dest, int color)
{
	t_bresenham	datas;

	datas.dx = dest.x - p1.x;
	datas.dy = dest.y - p1.y;
	datas.yi = 1;
	if (datas.dy < 0)
	{
		datas.yi = -1;
		datas.dy = -datas.dy;
	}
	datas.d = 2 * datas.dy - datas.dx;
	datas.y = p1.y;
	datas.cst1 = 2 * (datas.dy - datas.dx);
	datas.cst2 = 2 * datas.dy;
	datas.x = p1.x;
	while (datas.x < dest.x)
	{
		his_mlx_pixel_put(&global->minimap, datas.x, datas.y, color);
		if (datas.d > 0)
		{
			datas.y += datas.yi;
			datas.d += datas.cst1;
		}
		else
			datas.d += datas.cst2;
		++datas.x;
	}
}

/*
	Draw the ray
	https://lodev.org/cgtutor/raycasting.html
*/
void
	bresenham(t_global *global, t_vector2_f from, t_vector2_f dest, int color)
{
	if (fabs(dest.y - from.y) < fabs(dest.x - from.x))
	{
		if (from.x > dest.x)
			draw_x(global, dest, from, color);
		else
			draw_x(global, from, dest, color);
	}
	else
	{
		if (from.y > dest.y)
			draw_y(global, dest, from, color);
		else
			draw_y(global, from, dest, color);
	}
}
