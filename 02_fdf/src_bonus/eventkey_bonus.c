/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventkey_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 08:52:27 by jumarque          #+#    #+#             */
/*   Updated: 2025/03/24 10:58:49 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

char	*ft_theme(int i)
{
	if (i == 0)
		return ("Personalizado");
	if (i == 1)
		return ("Isla");
	if (i == 2)
		return ("Oceano");
	if (i == 3)
		return ("Montaña");
	return ("RGB");
}

void	ft_eventkey2(t_env *e, int keycode)
{
	if (keycode == KEY_LEFT)
		e->cnum -= (-5 * (e->cnum == 0) + 1);
	else if (keycode == KEY_RIGHT)
		e->cnum += (-5 * (e->cnum == 4) + 1);
	else if (keycode == KEY_P)
		e->tpro += (-2 * (e->tpro == 1) + 1);
	else if (keycode == KEY_F)
		e->wire = (-1 * (e->wire == 1) + 1);
}

int	ft_eventkey(t_env *e, int keycode, t_smem *mem)
{
	if (keycode == KEY_A)
		e->x_offset -= 100;
	else if (keycode == KEY_D)
		e->x_offset += 100;
	else if (keycode == KEY_W)
		e->y_offset -= 100;
	else if (keycode == KEY_S)
		e->y_offset += 100;
	else if (keycode == KEY_UP && e->scale < 150)
		e->scale *= 1.5;
	else if (keycode == KEY_DOWN && e->scale / 1.5 > 0.5)
		e->scale /= 1.5;
	else if (keycode == KEY_MENUS)
		e->height -= 1.0;
	else if (keycode == KEY_PLUS)
		e->height += 1.0;
	else if (keycode == KEY_Q)
		ft_revarray(e, 1, mem);
	else if (keycode == KEY_E)
		ft_revarray(e, -1, mem);
	else
		ft_eventkey2(e, keycode);
	return (0);
}

void	ft_displayparam(t_env *e)
{
	char	*var_h;
	char	*var_s;

	var_s = ft_itoa(e->scale * 10);
	var_h = ft_itoa(e->height * 10);
	mlx_string_put(e->mlx, e->win, 20, HEIGHT - 70, WHITE, "Tasa de relieve :");
	mlx_string_put(e->mlx, e->win, 135, HEIGHT - 70, WHITE, var_h);
	mlx_string_put(e->mlx, e->win, 20, HEIGHT - 56, WHITE, "Tema de color :");
	mlx_string_put(e->mlx, e->win, 135, HEIGHT - 56, WHITE, ft_theme(e->cnum));
	mlx_string_put(e->mlx, e->win, 20, HEIGHT - 42, WHITE, "Nivel de zoom :");
	mlx_string_put(e->mlx, e->win, 135, HEIGHT - 42, WHITE, var_s);
	mlx_string_put(e->mlx, e->win, 20, HEIGHT - 28, WHITE, "Proyeccion: ");
	if (e->tpro == 0)
		mlx_string_put(e->mlx, e->win, 135, HEIGHT - 28, WHITE, "Isometrica ");
	else
		mlx_string_put(e->mlx, e->win, 135, HEIGHT - 28, WHITE, "Paralela");
	mlx_string_put(e->mlx, e->win, 20, HEIGHT - 14, 0xFFFFFF, "Wireframe :");
	if (e->wire == 0)
		mlx_string_put(e->mlx, e->win, 135, HEIGHT - 14, WHITE, "Si");
	else
		mlx_string_put(e->mlx, e->win, 135, HEIGHT - 14, WHITE, "No");
	free(var_s);
	free(var_h);
}
