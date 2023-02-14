/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:50:56 by lgenevey          #+#    #+#             */
/*   Updated: 2023/02/14 12:33:43 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_global *g)
{
	t_vector2_f	futur;

	futur = g->player.pos;
	futur.x += cos(g->player.initial_angle) * g->player.speed;
	futur.y += sin(g->player.initial_angle) * g->player.speed;
	if (g->map_datas.map[pxl_to_coord(futur.y)][pxl_to_coord(futur.x)] == '0')
	{
		g->player.pos.x = futur.x;
		g->player.pos.y = futur.y;
	}
	printf("\\forwrd:\n");
	printf("P pos X:	%f\n", cos(g->player.initial_angle) * g->player.speed);
	printf("P pos Y:	%f\n", sin(g->player.initial_angle) * g->player.speed);
}

void	move_backward(t_global *g)
{
	t_vector2_f	futur;

	futur = g->player.pos;
	futur.x -= cos(g->player.initial_angle) * g->player.speed;
	futur.y -= sin(g->player.initial_angle) * g->player.speed;
	if (g->map_datas.map[pxl_to_coord(futur.y)][pxl_to_coord(futur.x)] == '0')
	{
		g->player.pos.x = futur.x;
		g->player.pos.y = futur.y;
	}
}

void	move_right(t_global *g)
{
	t_vector2_f	futur;

	futur = g->player.pos;
	futur.x += cos(g->player.initial_angle + deg_to_rad(90)) * g->player.speed;
	futur.y += sin(g->player.initial_angle + deg_to_rad(90)) * g->player.speed;
	if (g->map_datas.map[pxl_to_coord(futur.y)][pxl_to_coord(futur.x)] == '0')
	{
		g->player.pos.x = futur.x;
		g->player.pos.y = futur.y;
	}
}

void	move_left(t_global *g)
{
	t_vector2_f	futur;

	futur = g->player.pos;
	futur.x += cos(g->player.initial_angle + deg_to_rad(-90)) * g->player.speed;
	futur.y += sin(g->player.initial_angle + deg_to_rad(-90)) * g->player.speed;
	if (g->map_datas.map[pxl_to_coord(futur.y)][pxl_to_coord(futur.x)] == '0')
	{
		g->player.pos.x = futur.x;
		g->player.pos.y = futur.y;
	}
}

// static void	move_forward(t_global *g)
// {
// 	t_vector2_f futur;

// 	futur = g->player.pos;
// 	printf("\nactual X: %f\n", g->player.pos.x);
// 	printf("actual Y: %f\n\n", g->player.pos.y);

// 	futur.x += cos(g->player.initial_angle) * g->player.speed;
// 	futur.y += sin(g->player.initial_angle) * g->player.speed;
// 	printf("futur X: %f\n", futur.x);
// 	printf("futur Y: %f\n\n", futur.y);

// 	printf("actual coordonnee X: %d\n", pxl_to_coord(g->player.pos.x));
// 	printf("actual coordonnee Y: %d\n", pxl_to_coord(g->player.pos.y));
// 	printf("futur coordonnee X: %d\n", pxl_to_coord(futur.x));
// 	printf("futur coordonnee Y: %d\n\n", pxl_to_coord(futur.y));

// 	printf("futur X : %d\n",
//	g->map_datas.map[pxl_to_coord(futur.y)][pxl_to_coord(futur.x)]);
// 	if (g->map_datas.map[pxl_to_coord(futur.y)][pxl_to_coord(futur.x)] == '0')
// 	{
// 		g->player.pos.x += cos(g->player.initial_angle) * g->player.speed;
// 		g->player.pos.y += sin(g->player.initial_angle) * g->player.speed;
// 	}
// }
