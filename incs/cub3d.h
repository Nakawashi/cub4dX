/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:24:23 by lgenevey          #+#    #+#             */
/*   Updated: 2023/01/02 17:05:36 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
#include <sys/stat.h>

# include "mlx.h"
# include "libft.h"

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

/*
	on aura 4 variables de type t_img
*/
typedef struct s_img
{
	void	*img;
	char	*addr;
	char	*texture_path;
	int		img_width;
	int		img_height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_map
{
	char	**map;
	int		map_width;
	int		map_height;
}	t_map;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
}	t_player;

typedef struct s_ray
{
	char		*direction;
	t_player	player;
}	t_ray;

typedef struct s_global
{
	t_window	window;
	t_img		img;
}	t_global;

void	init_window(t_window *window);
void	quit_program(t_window *window);
char	**read_map(const char *path_to_file);

void	create_bg_img(t_window	*window, t_img *img);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

#endif
