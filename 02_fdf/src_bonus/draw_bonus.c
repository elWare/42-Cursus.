/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:49:05 by jumarque          #+#    #+#             */
/*   Updated: 2025/03/24 10:58:17 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	ft_draw_right_h(t_env *e, t_coord *p1, t_coord *p2)
{
	int		x;
	double	z;

	x = p1->x - 1;
	z = p1->z;
	while (++x <= p2->x)
	{
		ft_pixelput(e, x, p1->y + ((p2->y - p1->y) * (x - p1->x)) / \
			(p2->x - p1->x), ft_getlevel(e, z));
		z += e->pasz;
	}
}

void	ft_draw_left_h(t_env *e, t_coord *p1, t_coord *p2)
{
	int		x;
	double	z;

	x = p2->x - 1;
	z = p2->z;
	while (++x <= p1->x)
	{
		ft_pixelput(e, x, p2->y + ((p1->y - p2->y) * (x - p2->x)) / \
			(p1->x - p2->x), ft_getlevel(e, z));
		z += e->pasz;
	}
}

void	ft_draw_down_v(t_env *e, t_coord *p1, t_coord *p2)
{
	int		y;
	double	z;

	y = p1->y - 1;
	z = p1->z;
	while (++y <= p2->y)
	{
		ft_pixelput(e, p1->x + ((p2->x - p1->x) * (y - p1->y)) / \
		(p2->y - p1->y), y, ft_getlevel(e, z));
		z += e->pasz;
	}
}

void	ft_draw_up_v(t_env *e, t_coord *p1, t_coord *p2)
{
	int		y;
	double	z;

	y = p2->y - 1;
	z = p2->z;
	while (++y <= p1->y)
	{
		ft_pixelput(e, p2->x + ((p1->x - p2->x) * (y - p2->y)) / \
			(p1->y - p2->y), y, ft_getlevel(e, z));
		z += e->pasz;
	}
}

void	ft_drawline(t_env *e, t_coord *p1, t_coord *p2)
{
	if (ft_fabs(p2->x - p1->x) > ft_fabs(p2->y - p1->y))
		e->pasz = (p2->z - p1->z) / (p2->x - p1->x);
	else
		e->pasz = (p2->z - p1->z) / (p2->y - p1->y);
	if (p1->x <= p2->x && (p2->x - p1->x) >= ft_fabs(p2->y - p1->y))
		ft_draw_right_h(e, p1, p2);
	else if (p2->x <= p1->x && (p1->x - p2->x) >= ft_fabs(p1->y - p2->y))
		ft_draw_left_h(e, p1, p2);
	else if (p2->y <= p1->y && (p1->y - p2->y) >= ft_fabs(p1->x - p2->x))
		ft_draw_up_v(e, p1, p2);
	else if (p1->y <= p2->y && (p2->y - p1->y) >= ft_fabs(p2->x - p1->x))
		ft_draw_down_v(e, p1, p2);
}
