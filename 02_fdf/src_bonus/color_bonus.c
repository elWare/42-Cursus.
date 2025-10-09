/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 08:59:58 by jumarque          #+#    #+#             */
/*   Updated: 2025/03/24 10:58:00 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

int	ft_findcolor(t_color *color, int z, int z_min, int z_max)
{
	int		t1;
	int		t2;
	int		v;

	if (z <= z_min)
		return (color->color1);
	if (z >= z_max)
		return (color->color2);
	t1 = color->color1 / 256 / 256;
	t2 = color->color2 / 256 / 256;
	v = ((((z - ft_abs(z_min)) * (t2 - t1)) / \
		(z_max - ft_abs(z_min))) + t1) * 256 * 256;
	t1 = color->color1 / 256 % 256;
	t2 = color->color2 / 256 % 256;
	v += ((((z - ft_abs(z_min)) * (t2 - t1)) / \
	(z_max - ft_abs(z_min))) + t1) * 256;
	t1 = color->color1 % 256;
	t2 = color->color2 % 256;
	v += ((((z - ft_abs(z_min)) * (t2 - t1)) / \
	(z_max - ft_abs(z_min))) + t1);
	return (v);
}

int	ft_getlevel(t_env *e, double z)
{
	t_color		color;

	if (z < e->z_min || z > e->z_max)
		return (0);
	if (z <= e->z_mid && z >= e->z_min)
	{
		color.color1 = e->color[e->cnum][0];
		color.color2 = e->color[e->cnum][1];
		return (ft_findcolor(&color, z, e->z_min, e->z_mid));
	}
	else if (z <= e->z_max && z >= e->z_mid)
	{
		color.color1 = e->color[e->cnum][1];
		color.color2 = e->color[e->cnum][2];
		return (ft_findcolor(&color, z, e->z_mid, e->z_max));
	}
	return (0);
}

float	ft_fabs(float result)
{
	if (result < 0)
		result = -result;
	return (result);
}

int	ft_abs(int result)
{
	if (result < 0)
		result = -result;
	return (result);
}
