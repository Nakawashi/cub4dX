
#include "cub3d.h"

typedef struct s_raycasting {
	int		hit;
	int		side;
	int		mapx;
	int		mapy;
	int		step_x;
	int		step_y;
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	w;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	wallx;
	int		texwidth;
	int		texx;
	int		texy;
	double	texpos;
	int		lineheight;
	int		texheight;
	int		drawstart;
	int		drawend;
}				t_raycasting;




void	draw_column2(t_global *global, int *x)
{
    t_raycasting    *rc = malloc(sizeof(t_raycasting));

    rc->w = -1;
	rc->mapx = global->player.pos.x/8;
	rc->mapy = global->player.pos.y/8;
	rc->hit = 0;



    rc->camerax = 2 * *x / (float)WIN_HEIGTH - 1.0;
	rc->raydirx = cos(global->player.initial_angle) + 0.66 * rc->camerax;
	rc->raydiry = sin(global->player.initial_angle) + 1 * rc->camerax;

    rc->raydirx = cos(global->player.initial_angle);
	rc->raydiry = sin(global->player.initial_angle);

    printf("%f %f\n", rc->raydirx, rc->raydiry);
	if (rc->raydirx == 0)
		rc->deltadistx = INFINITY;
	else
		rc->deltadistx = fabs(1 / rc->raydirx);
	if (rc->raydiry == 0)
		rc->deltadisty = INFINITY;
	else
		rc->deltadisty = fabs(1 / rc->raydiry);




    if (rc->raydirx < 0)
	{
		rc->step_x = -1;
		rc->sidedistx = (global->player.pos.x - (float)rc->mapx) * rc->deltadistx;
	}
	else
	{
		rc->step_x = 1;
		rc->sidedistx = ((float)rc->mapx + 1.0f - global->player.pos.x) * rc->deltadistx;
	}
	if (rc->raydiry < 0)
	{
		rc->step_y = -1;
		rc->sidedisty = (global->player.pos.y - (float)rc->mapy) * rc->deltadisty;
	}
	else
	{
		rc->step_y = 1;
		rc->sidedisty = ((float)rc->mapy + 1.0f - global->player.pos.y) * rc->deltadisty;
	}



    while (rc->hit == 0)
	{
		if (rc->sidedistx < rc->sidedisty)
		{
			rc->sidedistx += rc->deltadistx;
			rc->mapx += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->sidedisty += rc->deltadisty;
			rc->mapy += rc->step_y;
			rc->side = 1;
		}
		if (global->map_datas.map[rc->mapy][rc->mapx] == '1')
			rc->hit = 1;
	}


    if (rc->side == 0 || rc->side == 2)
		rc->perpwalldist = (rc->sidedistx - rc->deltadistx);
	else
		rc->perpwalldist = (rc->sidedisty - rc->deltadisty);
    printf("%f\n", rc->perpwalldist);


    rc->lineheight = (WIN_HEIGTH / rc->perpwalldist);
	rc->drawstart = (rc->lineheight / -2) + WIN_HEIGTH/2;
	if (rc->drawstart < 0)
		rc->drawstart = 0;
	rc->drawend = (rc->lineheight / 2 + WIN_HEIGTH/2);
	if (rc->drawend >= WIN_HEIGTH)
		rc->drawend = WIN_HEIGTH - 1;






    // printf("%d %d\n", rc->drawstart, rc->drawend);
    int i = 0;

	while (i < WIN_HEIGTH)
	{
		if (i <= rc->drawstart)
			his_mlx_pixel_put(&global->render_img, *x, i, BLEU);
		else if (i > rc->drawend)
			his_mlx_pixel_put(&global->render_img, *x, i, JAUNE);
		else
		{
			if (rc->side == 0 && rc->raydirx > 0)
				his_mlx_pixel_put(&global->render_img, *x, i, G_FAV);
			else if (rc->side == 0 && rc->raydirx <= 0)
				his_mlx_pixel_put(&global->render_img, *x, i, BORDEAU);
			else if (rc->side == 1 && rc->raydiry >= 0)
				his_mlx_pixel_put(&global->render_img, *x, i, TRUC);
			else
				his_mlx_pixel_put(&global->render_img, *x, i, BLEUF);
		}
		++i;
	}

    

    bresenham(global, global->player.pos, (t_vector2_f){.x=rc->mapx*8, .y=rc->mapy*8}, PLUM);
}

