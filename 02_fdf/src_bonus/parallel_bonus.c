/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:55:16 by jumarque          #+#    #+#             */
/*   Updated: 2025/03/24 10:59:06 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

t_coord	ft_getparallelpoint(int x, int y, int z, t_env *e)
{
	t_coord	p;

	x *= e->scale;
	y *= e->scale;
	p.y = (x + e->y_offset) + (e->cte1 * (-z)) + e->y_origin;
	p.x = (y + e->x_offset) + e->cte3 * (-z * e->height) + e->x_origin;
	p.z = z;
	return (p);
}

void	ft_parallel(t_env *e)
{
	int		i;
	int		j;
	t_coord	p1;
	t_coord	p2;

	i = -1;
	while (++i < e->width)
	{
		j = e->length;
		while (--j >= 0)
		{
			p1 = ft_getparallelpoint(i, j, e->array[i][j], e);
			if (i < e->width - 1)
			{
				p2 = ft_getparallelpoint(i + 1, j, e->array[i + 1][j], e);
				ft_drawline(e, &p1, &p2);
			}
			if (j < e->length - 1)
			{
				p2 = ft_getparallelpoint(i, j + 1, e->array[i][j + 1], e);
				ft_drawline(e, &p1, &p2);
			}
		}
	}
}
