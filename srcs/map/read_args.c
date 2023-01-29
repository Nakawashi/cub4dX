#include "cub3d.h"

static int	is_img(char **line_args, t_global *glo, int *nbr_args);
static int	is_color(char **line_args, t_window *win, int *nbr_args);
static int	get_args(const char *line, t_global *global,
				t_window *win, int *nbr_args);

// Get length of a char **
int	ft_tab_length(char **tab)
{
	size_t	length;

	length = 0;
	while (tab[length])
		length++;
	return (length);
}

int	read_args(t_global *global, int fd)
{
	char	*line;
	int		nbr_args;

	nbr_args = 0;
	while (nbr_args < 6)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strchr(line, '\n') != NULL)
			*(ft_strchr(line, '\n')) = '\0';
		if (get_args(line, global, &global->window, &nbr_args) < 0)
		{
			free(line);
			return (-2);
		}
		free(line);
	}
	if (nbr_args < 6)
	{
		printf("ERROR\n Error parsing missing args\n");
		return (-1);
	}
	return (0);
}

// Check if arg is NO, if path is not already stored store it else return -1
// Do the same for each direction
// Else case : mean an arg is found but not recognized => not an error
// Nbr args is incremented only if a new path has ben stored
static int	is_img(char **line_args, t_global *glo, int *nbr_args)
{
	if (ft_strcmp(line_args[0], "NO") == 0 && glo->no.texture_path == NULL)
		glo->no.texture_path = ft_strdup_safe(line_args[1]);
	else if (ft_strcmp(line_args[0], "NO") == 0)
		return (-1);
	else if (ft_strcmp(line_args[0], "SO") == 0 && glo->so.texture_path == NULL)
		glo->so.texture_path = ft_strdup_safe(line_args[1]);
	else if (ft_strcmp(line_args[0], "SO") == 0)
		return (-1);
	else if (ft_strcmp(line_args[0], "WE") == 0 && glo->we.texture_path == NULL)
		glo->we.texture_path = ft_strdup_safe(line_args[1]);
	else if (ft_strcmp(line_args[0], "WE") == 0)
		return (-1);
	else if (ft_strcmp(line_args[0], "EA") == 0 && glo->ea.texture_path == NULL)
		glo->ea.texture_path = ft_strdup_safe(line_args[1]);
	else if (ft_strcmp(line_args[0], "EA") == 0)
		return (-1);
	else
		return (0);
	(*nbr_args)++;
	return (0);
}

static int	is_color(char **line_args, t_window *win, int *nbr_args)
{
	if (ft_strcmp(line_args[0], "C") == 0
		&& win->color_ceiling_hexa == NULL)
		win->color_ceiling_hexa = ft_strdup_safe(line_args[1]);
	else if (ft_strcmp(line_args[0], "C") == 0)
		return (-1);
	else if (ft_strcmp(line_args[0], "F") == 0
		&& win->color_floor_hexa == NULL)
		win->color_floor_hexa = ft_strdup_safe(line_args[1]);
	else if (ft_strcmp(line_args[0], "F") == 0)
		return (-1);
	else
		return (0);
	(*nbr_args)++;
	return (0);
}

static int	get_args(const char *line, t_global *global,
		t_window *win, int *nbr_args)
{
	char	**line_args;
	int		tab_len;

	line_args = ft_split(line, ' ');
	if (!line_args)
	{
		printf("ERROR\n Malloc error\n");
		return (-1);
	}
	tab_len = ft_tab_length(line_args);
	if (tab_len != 0 && tab_len != 2)
	{
		printf("ERROR\n Error not argument : line : %s\n", line);
		ft_free_ppointer(line_args);
		return (-1);
	}
	if (tab_len == 2 && (is_img(line_args, global, nbr_args) < 0
			|| is_color(line_args, win, nbr_args) < 0))
	{
		printf("ERROR\n Error parsing : duplicate arg : %s\n", line_args[0]);
		ft_free_ppointer(line_args);
		return (-2);
	}
	ft_free_ppointer(line_args);
	return (0);
}
