/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:19:45 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/13 20:28:42 by lgenevey         ###   ########.fr       */
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

t_vector2_f	dda(t_global *global, t_ray *ray)
{
	(void)ray;
	t_vector2_f	player; // player
	t_vector2_f	destination; // corrdinate of where we touch the wall
	t_vector2_f	direction; // x et y big triangle, complete, son hypotenuse est entre le player et le mur vise par le rayon
	t_vector2_f step; // either 1 or -1
	t_vector2_f	side_distance;
	t_vector2_f	delta_distance;


	// ray->direction.x = 0;
	// ray->direction.y = -1;

	player.x = global->player.position.x;
	player.y = global->player.position.y;
	destination.x = (int)player.x; // faire une fonction qui converti un vecteur de floats en vecteur de int
	destination.y = (int)player.y;
	// direction.x = ray->direction.x - player.x; // distance trait
	// direction.y = ray->direction.y - player.y;
	direction.x = cos(global->player.angle);
	direction.y = sin(global->player.angle);

	delta_distance.x = (direction.x == 0) ? 1e30 : fabs(1.0f / direction.x); // 1e30 is a large value
	delta_distance.y = (direction.y == 0) ? 1e30 : fabs(1.0f / direction.y);

	if (direction.x < 0)
	{
		step.x = -1; // Calculating X step (depending on the direction)
		side_distance.x = (player.x - destination.x) * delta_distance.x; // Calculating X gap to the nearest integer coordinate
	}
	else
	{
		step.x = 1;
		side_distance.x = (destination.x + 1.0f - player.x) * delta_distance.x;
	}

	if (direction.y < 0)
	{
		step.y = -1; // Calculating Y step (depending on the direction)
		side_distance.y = (player.y - destination.y) * delta_distance.y; // Calculating Y gap to the nearest integer coordinate
	}
	else
	{
		step.y = 1;
		side_distance.y = (destination.y + 1.0f - player.y) * delta_distance.y;
	}


	// boucle qui va faire avancer notre rayon jusqu'a toucher un mur
	while (1)
	{
		if (side_distance.x < side_distance.y)
		{
			side_distance.x += delta_distance.x;
			destination.x += step.x;
		}
		else
		{
			side_distance.y += delta_distance.y;
			destination.y += step.y;
		}

		// Converting pixel coordinates to tab coordinates
		t_vector2_d cell = {
			destination.x / MINI_WIDTH,
			destination.y / MINI_WIDTH
		};

		if (global->map_datas.map[cell.y][cell.x] == '1') // Is a wall
		{
			printf("dest x: %f\n", destination.x);
			printf("dest y: %f\n", destination.y);
			bresenham(global, player, destination, PLUM);
			return (destination);
		}
	}


// gestion des erreurs ci dessous
// // Using squared values is faster than using square root function
// float ray_length = get_vector_d_length_squared(origin, destination);

// while (ray_length < data->view_dst * data->view_dst)
// {
// 	if (side_distance.x < side_distance.y)
// 	{
// 		side_distance.x += delta_dist.x;
// 		destination.x += step.x;
// 	}
// 	else
// 	{
// 		side_distance.y += delta_dist.y;
// 		destination.y += step.y;
// 	}

// 	ray_length = get_vector_d_length_squared(origin, destination);

// 	// Converting pixel coordinates to tab coordinates
// 	t_vector2_d cell = {
// 		destination.x / data->cell_size,
// 		destination.y / data->cell_size
// 	};

// 	if (cell.x < 0 || cell.x >= data->win_width)
// 		continue;
// 	if (cell.y < 0 || cell.y >= data->win_height)
// 		continue;

// 	if (data->tab[cell.y][cell.x] == 1) // Is a wall
// 	{
// 		return (vector_d_to_f(destination));
// 	}
// }

}