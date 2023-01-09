/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:43:13 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/08 20:29:07 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	render_next_frame(t_global *global)
// {

// 	return (0);
// }

int	key_hook(int keycode, t_global *global)
{
	if (keycode == EVENT_KEY_ESC)
		clean(global);
	if (keycode == KEY_W)
		printf("you pressed w\n");
	if (keycode == KEY_A)
	printf("you pressed a\n");
	if (keycode == KEY_S)
		printf("you pressed s\n");
	if (keycode == KEY_D)
		printf("you pressed d\n");
	return (0);
}