#include "cub3d.h"

// Get length of a char **
int	ft_tab_length(char **tab)
{
	size_t	length;

	length = 0;
	while (tab[length])
		length++;
	return (length);
}