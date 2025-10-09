/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:56:52 by jumarque          #+#    #+#             */
/*   Updated: 2025/03/24 10:45:13 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_mlx_fill_image(t_env *e)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			ft_pixelput(e, x, y, BLACK);
		}
	}
}

int	ft_exposehook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	ft_mlx_fill_image(e);
	ft_isometric(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
	return (0);
}

int	ft_keyhook(int keycode, t_env *e, t_smem *mem)
{
	(void)mem;
	if (keycode == 65307 || keycode == 17)
		ft_close_window(e);
	ft_exposehook(e);
	return (0);
}

void	ft_displaytab(t_smem *mem)
{
	t_env	e;

	e = ft_initenv(mem);
	mlx_key_hook(e.win, ft_keyhook, &e);
	mlx_hook(e.win, 17, 0, ft_close_window, &e);
	mlx_expose_hook(e.win, ft_exposehook, &e);
	mlx_loop(e.mlx);
}
