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
static void	draw_y(t_global *global, t_vector2_f p1, t_vector2_f p2, int color)
{
	t_bresenham	datas;

	datas.dx = p2.x - p1.x;
	datas.dy = p2.y - p1.y;
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
	while (datas.y < p2.y)
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

static void	draw_x(t_global *global, t_vector2_f p1, t_vector2_f p2, int color)
{
	t_bresenham datas;

	datas.dx = p2.x - p1.x;
	datas.dy = p2.y - p1.y;
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
	while (datas.x < p2.x)
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
void	bresenham(t_global *global, t_vector2_f p1, t_vector2_f p2, int color)
{
	if (fabs(p2.y - p1.y) < fabs(p2.x - p1.x))
	{
		if (p1.x > p2.x)
			draw_x(global, p2, p1, color);
		else
			draw_x(global, p1, p2, color);
	}
	else
	{
		if (p1.y > p2.y)
			draw_y(global, p2, p1, color);
		else
			draw_y(global, p1, p2, color);
	}
}
