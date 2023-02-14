/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:49:49 by lgenevey          #+#    #+#             */
/*   Updated: 2023/02/14 17:10:13 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
