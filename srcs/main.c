/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:41:33 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/06 20:11:03 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// jaune:	0x00FFCE6D
// bleu:	0x0081D5FF

int	main(int argc, char **argv)
{
	t_global	global;
	(void)argc;
	(void)argv;

	init_window(&global.window);
	quit_program(&global.window);

	global.map.map = read_map("assets/map1.cub");
	if (!global.map.map)
		return (1);
	get_map_height(&global.map);
for (int i = 0; i < global.map.map_height; ++i)
	printf("%s\n", global.map.map[i]);

	//pourquoi je peux pas afficher les deux en meme temps omg
	my_mlx_put_ceiling(&global, 0, 0, BLEU);
	my_mlx_put_floor(&global, WIN_HEIGTH/2, 0, JAUNE);

	mlx_loop(&global.window.mlx_id);
	return (0);
}

/*
	put background (floor)
	ceiling sera calculé par rapport a la taille des pixels a afficher en vertical
*/