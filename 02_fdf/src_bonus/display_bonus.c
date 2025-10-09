/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:56:52 by jumarque          #+#    #+#             */
/*   Updated: 2025/03/24 10:58:13 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

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
	if (e->tpro == 0 && e->wire == 0)
		ft_isometric(e);
	else if (e->tpro == 0 && e->wire == 1)
		ft_isometricf(e);
	else if (e->tpro == 1)
		ft_parallel(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
	ft_displaymenu(e);
	ft_displayparam(e);
	return (0);
}

void	ft_displaymenu(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 20, 20, WHITE,
		"W, A, S, D para mover el objeto");
	mlx_string_put(e->mlx, e->win, 20, 34, WHITE,
		"+ y - en el teclado numerico para aumentar o disminuir el relieve");
	mlx_string_put(e->mlx, e->win, 20, 48, WHITE,
		"Q o E para cambiar la rotacion");
	mlx_string_put(e->mlx, e->win, 20, 62, WHITE,
		"Flechas -> o <- cambiar colores");
	mlx_string_put(e->mlx, e->win, 20, 76, WHITE,
		"Flechas ^ o v para zoom");
	mlx_string_put(e->mlx, e->win, 20, 90, WHITE,
		"P cambio proyeccion");
	mlx_string_put(e->mlx, e->win, 20, 104, WHITE,
		"F cambio relleno");
	mlx_string_put(e->mlx, e->win, 20, 118, WHITE,
		"(opcion solo disponible para visualizacion isometrica)");
}

int	ft_keyhook(int keycode, t_env *e, t_smem *mem)
{
	if (keycode == 65307 || keycode == 17)
		ft_close_window(e);
	else
		ft_eventkey(e, keycode, mem);
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
