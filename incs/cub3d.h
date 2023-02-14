/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:24:23 by lgenevey          #+#    #+#             */
/*   Updated: 2023/02/14 11:08:06 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <sys/stat.h>

# include "mlx.h"
# include "libft.h"

//###############################
//								#
//			DEFINES				#
//								#
//###############################

// Window
# define WIN_WIDTH 1024
# define WIN_HEIGTH 512

// Minimap
// Careful could have to update init_position file if this value is changed
// Si valeur paire : afficher 4 pixels. Si valeur impair : afficher 1 pixel
# define MINI_WIDTH 8
# define MINI_HEIGHT 8

# define TEXTURE_SIZE 32

//colors
# define BLEU 0x0081D5FF
# define JAUNE 0x00FFCE6D
# define BORDEAU 0x005F021F
# define BLEUF 0x00001BEC
# define G_FAV 0x008700AF
# define TRUC 0x0087FFAF
# define BLACK 0x00000000
# define PLUM 0x00DDA0DD
# define WHITE 0x00FFFFFF
# define PINK 0x00EE5983
# define RED 0x00FF0000
# define TRANSP 0xFF000000

// "evenements du clavier mais en fait non"
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define ARROW_UP 126
# define ARROW_LEFT 123
# define ARROW_DOWN 125
# define ARROW_RIGHT 124
# define KEY_ESC 53

# define FOV 60
# define CUB_SIZE 128


// events a ne pas confondre avec les "evenements du clavier"
enum e_events
{
	KEY_DOWN = 2,
	KEY_UP = 3,
	MOUSE_DOWN = 4,
	MOUSE_UP = 5,
	ON_DESTROY = 17
};

typedef struct s_vector2_f
{
	float	x;
	float	y;
}	t_vector2_f;

typedef struct s_vector2_d
{
	int	x;
	int	y;
}	t_vector2_d;

typedef struct s_window
{
	void	*mlx_id;
	void	*win_id;
	char	*color_floor_hexa;
	char	*color_ceiling_hexa;
	int		color_floor_int;
	int		color_ceiling_int;
}	t_window;

/*
	on aura 4 variables de type t_img
*/
typedef struct s_img
{
	void	*img;
	int		*addr;
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

/*
	x and y are for initial position in map
*/
typedef struct s_player
{
	t_img		img;
	t_vector2_f	pos;
	char		direction;
	float		initial_angle;
	float		speed;
}	t_player;

/*
	float coordinates.
	better performances, less precision than double.
	https://b-bischoff.github.io/web/cube3d.html

	direction : plot right or left side
	i_cell (impact_cell): dest's coordinates, where our ray touches the wall
	side_hit : wich side of the wall is hit (nsew)
	side_dir : vertical or horizontal
	wallX : point touché sur le mur (0 - 8)
	coordonnée y si side_hit == v, coordonnée x si side_hit == h
*/
typedef struct s_ray
{
	t_vector2_f	dir;
	t_vector2_f	i_cell;
	t_vector2_f	side_dist;
	t_vector2_f step;
	t_vector2_f	delta_dist;
	t_player	player;
	float		ray_len;
	float		wallX;
	float		stick_size;
	char		side_hit;
	char		side_dir;
}	t_ray;

typedef struct s_global
{
	t_window	window;
	t_map		map_datas;
	t_img		background_img;
	t_img		minimap;
	t_img		render_img;
	t_img		no;
	t_img		so;
	t_img		we;
	t_img		ea;
	t_player	player;
	t_ray		ray;
	int			texture;
}	t_global;

//------------------------------//
//								//
//			GENERAL				//
//								//
//------------------------------//

void		init_window(t_window *window);
void		init_interface(t_global *global, char *map);
void		init_background(t_global *global, int x, int y);
int			clean(t_global *global);

//------------------------------//
//								//
//			IMAGES				//
//								//
//------------------------------//

void		his_mlx_pixel_put(t_img *img, int x, int y, int color);
int			get_pixel_color(t_img *img, int x, int y);
void		init_img_struct(t_img *img);
void		create_image(t_img *img, t_window *mlx_id, int width, int height);
int			open_image(t_img *img, t_window *mlx_id, char *filename);

//------------------------------//
//								//
//			THE MAP				//
//								//
//------------------------------//

int			read_file(t_global *global, char *path_to_file);
int			read_args(t_global *global, int fd);
int			read_map(t_global *global, int fd);

int			check_map(t_map *mapinfo, t_player *pl);
int			check_player(t_map *mapinfo, t_player *pl);
int			check_illegal_chars(t_map *mapinfo);
int			check_cases(t_map *mapinfo);
int			square_map(t_map *mapinfo);

int			parse_colors(t_global *global);
int			ft_tab_length(char **tab);


//------------------------------//
//								//
//			MINIMAP				//
//								//
//------------------------------//

void		my_mlx_put_square(t_img *img, t_vector2_d pos, int size, int color);
void		init_minimap(t_global *global);
void		draw_minimap(t_global *global);

//------------------------------//
//								//
//			EVENTS				//
//								//
//------------------------------//

//int		render_next_frame(void);
int			key_hook(int keycode, t_global *global);
void		handle_events(t_global *global);

//------------------------------//
//								//
//			PLAYER				//
//								//
//------------------------------//

float		coordinate_to_pixels(int n);
int			pixels_to_coordinate(float n);
void		init_player(t_global *global, t_vector2_f pos, int color);
void		get_player_coordinates(char **map, t_vector2_f position);

//------------------------------//
//								//
//			MATHS UTILS			//
//								//
//------------------------------//

float		deg_to_rad(float degree);
float		radians_to_degrees(float radian);
float		get_delta_distance(float direction);
void		bresenham(t_global *global, t_vector2_f p1, t_vector2_f p2, int color);
float		map(long pos, long in_max, long out_min);

//------------------------------//
//								//
//			RENDER				//
//								//
//------------------------------//

void		init_rainbow(t_global *global);
void		draw_rainbow(t_global *global);

//------------------------------//
//								//
//				DDA				//
//								//
//------------------------------//

int			dda(t_global *g, t_ray *ray, float angle);

#endif
