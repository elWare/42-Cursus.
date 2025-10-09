/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:38:47 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/09 09:22:51 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	*ft_putcolor(t_smem *mem, int r, int g, int b)
{
	int	*color;

	color = malloc(sizeof(int) * 3);
	if (!color)
		ft_error(mem, 0);
	color[0] = r;
	color[1] = g;
	color[2] = b;
	return (color);
}

void	ft_getcolor(t_smem *mem)
{
	int	**color;

	color = malloc(sizeof(int *) * 1);
	if (!color)
		ft_error(mem, 0);
	mem->color = color;
	color[0] = ft_putcolor(mem, 0x123456, 0x808080, 0xFFFFFF);
}

int	**ft_tabmalloc(int x, int y)
{
	int	i;
	int	**array;

	i = -1;
	array = malloc(sizeof(int *) * x);
	if (!array)
		return (NULL);
	while (++i < x)
	{
		array[i] = malloc(sizeof(int *) * y);
		if (!array[i])
		{
			ft_freearray(array, i, y);
			return (NULL);
		}
	}
	return (array);
}
