/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:14:03 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/08 17:37:45 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	get coordinates we found for the player (NSEW) and convert them into pixels
	-->then put the pixel in the middle of the square

	J : x * 7 - ((7/2) + 1) = position x in pixels
	I : y * 7 - ((7/2) + 1) = position x in pixels

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