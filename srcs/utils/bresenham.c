#include "cub3d.h"


static void	plot_line_high(t_global *global, t_vector2_f p1, t_vector2_f p2, int color)
{
	int dx = p2.x - p1.x;
	int dy = p2.y - p1.y;
	int xi = 1;

	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	int d = 2 * dx - dy;
	int x = p1.x;

	// Calculating const
	int cst1 = 2 * (dx - dy);
	int cst2 = 2 * dx;

	for (int y = p1.y; y < p2.y; y++)
	{
		his_mlx_pixel_put(&global->minimap, x, y, color);
		if (d > 0)
		{
			x += xi;
			d += cst1;
		}
		else
			d += cst2;
	}
}

static void	plot_line_low(t_global *global, t_vector2_f p1, t_vector2_f p2, int color)
{
	int dx = p2.x - p1.x;
	int dy = p2.y - p1.y;
	int yi = 1;

	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	int d = 2 * dy - dx;
	int y = p1.y;

	// Calculating const
	int cst1 = 2 * (dy - dx);
	int cst2 = 2 * dy;

	for (int x = p1.x; x < p2.x; x++)
	{
		his_mlx_pixel_put(&global->minimap, x, y, color);
		if (d > 0)
		{
			y += yi;
			d += cst1;
		}
		else
			d += cst2;
	}
}

void	bresenham(t_global *global, t_vector2_f p1, t_vector2_f p2, int color)
{
	if (fabs(p2.y - p1.y) < fabs(p2.x - p1.x))
	{
		if (p1.x > p2.x)
			plot_line_low(global, p2, p1, color);
		else
			plot_line_low(global, p1, p2, color);
	}
	else
	{
		if (p1.y > p2.y)
			plot_line_high(global, p2, p1, color);
		else
			plot_line_high(global, p1, p2, color);
	}
}
