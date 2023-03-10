/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:09:57 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/30 18:11:17 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
---- GET_NEXT_LINE ----
decscription :
write a function which returns a line read from a file descriptor
arguments :
fd : file descriptor, id unique du fichier a lire. Le 0 1 et 2 sont reserves
pour les entrees et sorties std et les erreurs
la prochaine ligne lue

*/

/*
gcc -Wall -Wextra -Werror *.c -g
lldb ./a.out
run
b : breakpoint
b [function_name]
b -l || b --line : breakpoint par rappot a la ligne
display
c : continue

*/

/*
 * cree une chaine de caracteres qui se termine soit par \n soit par \0
 * d'apres ce qu'il y a dans la static
 * en argument :leftover
 * en sortie : line
 */
char	*ft_fill_line(char *statiq)
{
	unsigned int	i;
	char			*s2;

	if (!statiq[0])
		return (NULL);
	s2 = NULL;
	i = 0;
	while (statiq[i] != '\0')
	{
		if (statiq[i] == '\n')
		{
			i++;
			s2 = ft_substr(statiq, 0, i);
			return (s2);
		}
		i++;
	}
	if (statiq[i] == '\0')
	{
		s2 = ft_strdup_safe(statiq);
		return (s2);
	}
	return (0);
}

/*
 * retourne leftover avec uniquement la partie non utilisee dans line
 * statiq = leftover
 * s = line
 * aussi on free la partie abandonee dans leftover car perdue a tout jamais
*/
char	*ft_overwrite_statiq(char *statiq, char *s)
{
	char	*temp;
	int		s_length;
	int		statiq_length;

	if (!s)
	{
		free(statiq);
		return (NULL);
	}
	s_length = ft_strlen(s);
	statiq_length = ft_strlen(statiq);
	temp = ft_substr(statiq, s_length, statiq_length - s_length);
	free(statiq);
	return (temp);
}

/*
	read file and return filled static variable to save infos
 */
char	*ft_read_buffer(int fd, char *statiq)
{
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		been_read;

	been_read = 1;
	while (!ft_find_char(statiq, '\n') && been_read != 0)
	{
		been_read = read(fd, buffer, BUFFER_SIZE);
		if (been_read == -1)
			return (NULL);
		buffer[been_read] = '\0';
		statiq = ft_strjoin_free(statiq, buffer);
	}
	return (statiq);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*leftover;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	leftover = ft_read_buffer(fd, leftover);
	if (!leftover)
		return (NULL);
	line = ft_fill_line(leftover);
	leftover = ft_overwrite_statiq(leftover, line);
	return (line);
}
