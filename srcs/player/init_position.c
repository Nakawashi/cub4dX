/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:14:03 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/08 20:24:18 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	get coordinates we found for the player (NSEW) and convert them into pixels
	-->then put the pixel in the middle of the square with the -2

	J : x * MINI_SIDE_SIZE - ((MINI_SIDE_SIZE/2) -2) = position x in pixels
	I : y * MINI_SIDE_SIZE - ((MINI_SIDE_SIZE/2) -2) = position x in pixels

	7 is MINI_WIDTH size for now. It's square so W and H are same.
	n is j (x) or i (y).
*/
int	coordinate_to_pixels(int n)
{
	return (n * MINI_WIDTH + (MINI_WIDTH/2) - 2);
	//return (n * MINI_WIDTH);
}

// [x	-	j	-	width	-	lines]
// [y	-	i	-	height	-	columns]
// [x	-	j	-	width	-	lines]
// [y	-	i	-	height	-	columns]
// [x	-	j	-	width	-	lines]
// [y	-	i	-	height	-	columns]
// [x	-	j	-	width	-	lines]
// [y	-	i	-	height	-	columns]
// [x	-	j	-	width	-	lines]
// [y	-	i	-	height	-	columns]
// [x	-	j	-	width	-	lines]
// [y	-	i	-	height	-	columns]
// [x	-	j	-	width	-	lines]
// [y	-	i	-	height	-	columns]
// OK