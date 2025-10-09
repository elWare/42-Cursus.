/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:18:54 by jumarque          #+#    #+#             */
/*   Updated: 2025/03/26 20:24:49 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_initsmem(t_smem *mem)
{
	mem->len = 0;
	mem->wid = 0;
	mem->color = NULL;
	mem->array = NULL;
	mem->line = NULL;
	mem->list = NULL;
}

void	ft_getminmax(t_env *e)
{
	int	i;
	int	j;

	i = -1;
	e->z_min = e->array[0][0];
	e->z_max = e->z_min;
	while (++i < e->width)
	{
		j = -1;
		while (++j < e->length)
		{
			if (e->array[i][j] > e->z_max)
				e->z_max = e->array[i][j];
			else if (e->array[i][j] < e->z_min)
				e->z_min = e->array[i][j];
		}
	}
}

void	ft_absarray(t_env *e)
{
	int	i;
	int	j;

	if (e->z_min < 0)
	{
		i = -1;
		while (++i < e->width)
		{
			j = -1;
			while (++j < e->length)
				e->array[i][j] += -e->z_min;
		}
		e->z_max += -e->z_min;
		e->z_min = 0;
	}
}

void	ft_initimg(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "FDF@42");
	e->img.img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->img.img = mlx_get_data_addr(e->img.img_ptr, &e->img.bpp, \
							&e->img.sl, &e->img.endian);
}

t_env	ft_initenv(t_smem *mem)
{
	t_env	e;

	e.mem = mem;
	e.x_offset = 0;
	e.y_offset = 0;
	e.x_origin = 10;
	e.y_origin = HEIGHT / 2;
	e.array = mem->array;
	e.length = mem->len;
	e.width = mem->wid;
	e.height = 1;
	e.tpro = 1;
	e.wire = 0;
	ft_getminmax(&e);
	ft_absarray(&e);
	e.color = mem->color;
	e.cnum = 0;
	e.z_mid = (e.z_min + e.z_max) / 2.0;
	e.scale = 0.9 * ((double)(WIDTH + HEIGHT) / (double)(e.width + e.length));
	e.cte1 = 0.5;
	e.cte2 = 0.5;
	e.cte3 = e.cte1 / 2.0;
	e.cte4 = e.cte2 / 2.0;
	ft_initimg(&e);
	return (e);
}
