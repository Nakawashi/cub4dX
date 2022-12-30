/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:41:33 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/30 14:27:41 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int	main(int argc, char **argv)
{
	t_window	window;
	(void)argc;
	(void)argv;

	init_window(&window);
	quit_program(&window);
	mlx_loop(window.mlx_id);

	return (0);
}