/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:24:23 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/30 14:45:41 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>

// open
# include <fcntl.h>

# include "../minilibx/mlx.h"
# include "../libft/libft.h"

// Quit game
# define EVENT_KEY_ESC 53
# define EVENT_KEY_EXIT 17

// size of img in pixel
# define IMG_SIZE 64

// ascii code for each lowercase letter and arrow
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

typedef struct s_window
{
	void	*mlx_id;
	void	*win_id;
	char	*color_ground;
	char	*color_ceiling;
	int		win_width;
	int		win_height;

}	t_window;

typedef struct s_img
{
	char	*no_texture_path;
	char	*so_texture_path;
	char	*we_texture_path;
	char	*ea_texture_path;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_player
{

}	t_player;

void	init_window(t_window *window);
void	quit_program(t_window *window);

#endif