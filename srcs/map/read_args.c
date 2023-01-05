








#include "cub3d.h"

// Get length of a char **
int ft_tab_length(char **tab)
{
	size_t	length;

	length = 0;
	while (tab[length])
		length++;
	return (length);
}


struct s_tmpstruct 
{
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;
};

// Check if arg is NO, if path is not already stored store it else return -1
// Do the same for each direction
// Else case : mean an arg is found but not recognized => not an error
// Nbr args is incremented only if a new path has ben stored
static int	is_img(char **line_args, struct s_tmpstruct *imgs, int *nbr_args)
{
	if (ft_strcmp(line_args[0], "NO") == 0 && imgs->no.texture_path == NULL)
		imgs->no.texture_path = ft_strdup_safe(line_args[1]);
	else if (ft_strcmp(line_args[0], "NO") == 0)
		return (-1);

	else if (ft_strcmp(line_args[0], "SO") == 0 && imgs->so.texture_path == NULL)
		imgs->so.texture_path = ft_strdup_safe(line_args[1]);
	else if (ft_strcmp(line_args[0], "SO") == 0)
		return (-1);

	else if (ft_strcmp(line_args[0], "WE") == 0 && imgs->we.texture_path == NULL)
		imgs->we.texture_path = ft_strdup_safe(line_args[1]);
	else if (ft_strcmp(line_args[0], "WE") == 0)
		return (-1);

	else if (ft_strcmp(line_args[0], "EA") == 0 && imgs->ea.texture_path == NULL)
		imgs->ea.texture_path = ft_strdup_safe(line_args[1]);
	else if (ft_strcmp(line_args[0], "EA") == 0)
		return (-1);
	
	else
		return (0);

	printf("Got arg %s\n", line_args[0]);
	(*nbr_args)++;
	return (0);
}

static int	is_color(char **line_args, struct s_window *winstruct, int *nbr_args)
{
	if (ft_strcmp(line_args[0], "C") == 0 && winstruct->color_ceiling == NULL)
		winstruct->color_ceiling = ft_strdup_safe(line_args[1]);
	else if (ft_strcmp(line_args[0], "C") == 0)
		return (-1);
	
	else if (ft_strcmp(line_args[0], "F") == 0 && winstruct->color_ground == NULL)
		winstruct->color_ground = ft_strdup_safe(line_args[1]);
	else if (ft_strcmp(line_args[0], "F") == 0)
		return (-1);

	else
		return (0);

	(*nbr_args)++;
	return (0);
}


static int	get_args(const char *line, struct s_tmpstruct *imgs, struct	s_window *winstruct, int *nbr_args)
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
	// (void)(1 || is_color(line_args, winstruct, nbr_args) < 0);
	if (tab_len == 2 && (is_img(line_args, imgs, nbr_args) < 0|| is_color(line_args, winstruct, nbr_args) < 0))
	{
		printf("ERROR\n Error parsing : duplicate arg : %s\n", line_args[0]);
		ft_free_ppointer(line_args);
		return (-2);
	}
	ft_free_ppointer(line_args);
	return (0);
}


void	init_tmpstruct(struct s_tmpstruct *imgs)
{
	ft_bzero(&imgs->no, sizeof(t_img));
	ft_bzero(&imgs->so, sizeof(t_img));
	ft_bzero(&imgs->we, sizeof(t_img));
	ft_bzero(&imgs->ea, sizeof(t_img));
}

int		read_args(int fd)
{
	char	*line;
	int		nbr_args;
	struct	s_tmpstruct imgs;
	struct	s_window 	winstruct;

	winstruct.color_ceiling = NULL;
	winstruct.color_ground = NULL;
	init_tmpstruct(&imgs);

	nbr_args = 0;
	while (nbr_args < 6)
	{
		line = get_next_line(fd);
		if (!line)
			break ;

		if (ft_strchr(line, '\n') != NULL)
			*(ft_strchr(line, '\n')) = '\0';

		// printf("gnl %s\n", line);
		if (get_args(line, &imgs, &winstruct, &nbr_args) < 0)
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


	printf("path no %s\n", imgs.no.texture_path);
	printf("path so %s\n", imgs.so.texture_path);
	printf("path we %s\n", imgs.we.texture_path);
	printf("path ea %s\n", imgs.ea.texture_path);
	printf("color ceil %s\n", winstruct.color_ceiling);
	printf("color floor %s\n", winstruct.color_ground);
	return (0);
}