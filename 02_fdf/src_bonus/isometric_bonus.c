/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 08:58:07 by jumarque          #+#    #+#             */
/*   Updated: 2025/03/24 10:59:02 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

t_coord	ft_getisompoint(int x, int y, int z, t_env *e)
{
	t_coord	p;

	x *= e->scale;
	y *= e->scale;
	p.x = (e->cte1 * (x + e->x_offset) + e->cte2 * y) + e->x_origin;
	p.y = ((e->cte3) * (x + e->y_offset) - \
			(e->cte4) * y) - (z * e->height) + e->y_origin;
	p.z = z;
	return (p);
}

void	ft_isometric(t_env *e)
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
			p1 = ft_getisompoint(i, j, e->array[i][j], e);
			if (i < e->width -1)
			{
				p2 = ft_getisompoint(i + 1, j, e->array[i + 1][j], e);
				ft_drawline(e, &p1, &p2);
			}
			if (j < e->length - 1)
			{
				p2 = ft_getisompoint(i, j +1, e->array[i][j + 1], e);
				ft_drawline(e, &p1, &p2);
			}
		}
	}
}

void	ft_isometricf(t_env *e)
{
	int			i;
	int			j;
	t_mcoord	p;

	i = -1;
	while (++i < e->width)
	{
		j = e->length;
		while (--j >= 0)
		{
			if (i > 0 && j > 0)
			{
				p.p1 = ft_getisompoint(i - 1, j - 1, \
				e->array[i - 1][j - 1], e);
				p.p2 = ft_getisompoint(i, j - 1, e->array[i][j - 1], e);
				p.p3 = ft_getisompoint(i, j, e->array[i][j], e);
				p.p4 = ft_getisompoint(i - 1, j, e->array[i - 1][j], e);
				ft_drawtriangle(&p.p1, &p.p2, &p.p3, e);
				ft_drawtriangle(&p.p1, &p.p4, &p.p3, e);
			}
		}
	}
}
