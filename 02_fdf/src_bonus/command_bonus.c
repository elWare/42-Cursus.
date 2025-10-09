/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:38:47 by jumarque          #+#    #+#             */
/*   Updated: 2025/03/24 10:58:05 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

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

void	ft_getcolor(t_smem *mem, char **argv, int argc)
{
	int	**color;

	color = malloc(sizeof(int *) * 5);
	if (!color)
		ft_error(mem, 0);
	mem->color = color;
	if (argc > 4)
	{
		color[0] = malloc(sizeof(int *) * 3);
		if (!*color)
			ft_error(mem, 0);
		color[0][0] = ft_atoi(argv[2]);
		color[0][1] = ft_atoi(argv[3]);
		color[0][2] = ft_atoi(argv[4]);
	}
	else
		color[0] = ft_putcolor(mem, 0x000000, 0x808080, 0xFFFFFF);
	color[1] = ft_putcolor(mem, 0x0070e0, 0x42c6ff, 0xf3d85e);
	color[2] = ft_putcolor(mem, 0xb9280e, 0x3d231a, 0x27160c);
	color[3] = ft_putcolor(mem, 0x124511, 0x1a0f0f, 0x888181);
	color[4] = ft_putcolor(mem, 0x0000ff, 0x00ff00, 0xff0000);
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

void	ft_revarray(t_env *e, int dir, t_smem *mem)
{
	int	i;
	int	j;
	int	**newtab;

	newtab = ft_tabmalloc(e->length, e->width);
	if (!newtab)
		ft_error(mem, 0);
	i = -1;
	while (++i < e->width)
	{
		j = -1;
		while (++j < e->length)
		{
			if (dir == 1)
				newtab[e->length - (j + 1)][i] = e->array[i][j];
			else
				newtab[j][e->width - (i + 1)] = e->array[i][j];
		}
	}
	ft_freearray(e->array, e->width, e->length);
	i = e->width;
	e->width = e->length;
	e->length = i;
	e->array = newtab;
}
