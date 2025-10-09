/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heigh_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 08:55:03 by jumarque          #+#    #+#             */
/*   Updated: 2025/03/24 10:58:59 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	ft_horline(t_env *e, t_coord *p1, t_coord *p2, int x)
{
	double	pasz;
	int		y;
	double	z;

	pasz = (double)(p2->z - p1->z) / (double)(p2->y - p1->y);
	if (p1->y <= p2->y)
	{
		y = p1->y - 1;
		z = p1->z;
		while (++y < p2->y && (z <= e->z_max && z >= e->z_min))
		{
			ft_pixelput(e, x, y, ft_getlevel(e, z));
			z += pasz;
		}
	}
	if (p1->y >= p2->y)
	{
		y = p2->y - 1;
		z = p2->z;
		while (++y < p1->y && (z <= e->z_max && z >= e->z_min))
		{
			ft_pixelput(e, x, y, ft_getlevel(e, z));
			z += pasz;
		}
	}
}
