/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:41:33 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/30 18:29:17 by lgenevey         ###   ########.fr       */
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
	map.map = read_map("../assets/map1.cub");
	if (!map.map)
		return (0);
	for (int i = 0; i < 5; ++i)
	{
		printf("%s\n", map.map[i]);
	}
	mlx_loop(window.mlx_id);
	return (0);
}
