/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:01:41 by jumarque          #+#    #+#             */
/*   Updated: 2025/03/28 10:50:43 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_error(t_smem *mem, int value)
{
	ft_freecolor(mem->color);
	exit (value);
}

void	ft_free(char **buff01, char **buff02)
{
	free(*buff01);
	free(*buff02);
}

int	ft_close_window(t_env *data)
{
	ft_freearray(data->array, data->width, data->length);
	ft_freecolor(data->color);
	mlx_destroy_window(data->mlx, data->win);
	mlx_loop_end(data->mlx);
	exit(0);
	return (0);
}
