/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 08:34:22 by jumarque          #+#    #+#             */
/*   Updated: 2025/03/24 10:53:38 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../libft/libft.h"

int	**ft_freearray(int **array, int wid, int len)
{
	int	i;

	i = -1;
	(void)len;
	while (++i < wid)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	return (NULL);
}

int	**ft_freecolor(int **color)
{
	int	i;

	i = -1;
	while (++i < 1)
		free(color[i]);
	return (NULL);
}

void	ft_gnl_cleanup(char **str_ptr)
{
	if (*str_ptr)
		free(*str_ptr);
}

char	**ft_freeline(char **line)
{
	char	**ptr_line;

	ptr_line = line;
	while (*ptr_line)
	{
		free(*ptr_line);
		*ptr_line = NULL;
		ptr_line++;
	}
	free(line);
	return (NULL);
}
