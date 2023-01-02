/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:41:33 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/02 22:59:29 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// jaune:	0x00FFCE6D
// blue:	0x0081D5FF

int	main(int argc, char **argv)
{
	t_global	global;
	t_map		map;
	(void)argc;
	(void)argv;

	init_window(&global.window);
	quit_program(&global.window);
	map.map = read_map("assets/map1.cub");
	if (!map.map)
		return (0);
	for (int i = 0; i < 5; ++i)
		printf("%s\n", map.map[i]);
	my_mlx_put_rectangle(&global, 0, 0, 0x00FFCE6D);
	mlx_loop(&global.window.mlx_id);
	return (0);
}
