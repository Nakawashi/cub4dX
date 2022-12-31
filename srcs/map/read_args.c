








#include "cub3d.h"

// Get length of a char **
int ft_tab_length(const char **tab)
{
	size_t	length;

	length = 0;
	while (tab[length])
		length++;
	return (length);
}


// Check if arg is NO, if path is not already stored store it else return -1
// Do the same for each direction
// Else case : mean an arg is found but not recognized => not an error
// Nbr args is incremented only if a new path has ben stored
int	is_img(char **line_args, int *nbr_args)
{
	if (ft_strcmp(lines_args[0], "NO") == 0 && path_to_no == NULL)
		path_to_no = ft_strdup_safe(lines_args[1]);
	else if (ft_strcmp(lines_args[0], "NO"))
		return (-1);

	else if (ft_strcmp(lines_args[0], "NO") == 0 && path_to_no == NULL)
		path_to_no = ft_strdup_safe(lines_args[1]);
	else if (ft_strcmp(lines_args[0], "NO"))
		return (-1);

	else if (ft_strcmp(lines_args[0], "NO") == 0 && path_to_no == NULL)
		path_to_no = ft_strdup_safe(lines_args[1]);
	else if (ft_strcmp(lines_args[0], "NO"))
		return (-1);

	else if (ft_strcmp(lines_args[0], "NO") == 0 && path_to_no == NULL)
		path_to_no = ft_strdup_safe(lines_args[1]);
	else if (ft_strcmp(lines_args[0], "NO"))
		return (-1);
	
	else
		return (0);

	*nbr_args++;
	return (0);
}

int	is_color(char **line_args, int *nbr_args)
{
	if (ft_strcmp(lines_args[0], "C") == 0 && path_to_no == NULL)
		path_to_no = ft_strdup_safe(lines_args[1]);
	else if (ft_strcmp(lines_args[0], "C"))
		return (-1);

	else if (ft_strcmp(lines_args[0], "F") == 0 && path_to_no == NULL)
		path_to_no = ft_strdup_safe(lines_args[1]);
	else if (ft_strcmp(lines_args[0], "F"))
		return (-1);
	else
		return (0);

	*nbr_args++;
	return (0);
}


int	get_args(const char *line, int *nbr_args)
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
		printf("ERROR\n Error parsing : line : %s\n", line);
		ft_free_ppointer(line_args);
		return (-1);
	}
	if (is_img(line_args, nbr_args) < 0 || is_color(line_args, nbr_args) < 0)
	{
		printf("ERROR\n Error parsing : duplicate arg : %s\n", line_args[0]);
		ft_free_ppointer(line_args);
		return (-2);
	}
}


char	**read_args(int fd)
{
	char	*line;
	int		nbr_args;

	nbr_args = 0;
	while (nbr_args < 6)
	{
		line = get_next_line(fd);
		if (!line)
			break ;

		if (get_args(line, &nbr_args) < 0)
		{
			free(line);
			return (-2);
		}
		
		free(line);
	}

	if (nbr_args < 6)
	{
		printf("ERROR\n Error parsing missing args");
		return (-1);
	}
}