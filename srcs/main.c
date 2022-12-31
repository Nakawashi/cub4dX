/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakawashi <nakawashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:41:33 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/31 13:34:47 by nakawashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_window	window;
	t_map		map;
	(void)argc;
	(void)argv;

	init_window(&window);
	quit_program(&window);
	map.map = read_map("../assets/test.txt");
	if (!map.map)
		return (0);
	for (int i = 0; i < 5; ++i)
	{
		printf("%s\n", map.map[i]);
	}
	mlx_loop(window.mlx_id);
	return (0);
}
