/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:14:08 by jumarque          #+#    #+#             */
/*   Updated: 2024/10/18 10:19:47 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printc(unsigned char c, va_list args)
{
	char	ca;

	if (c == 'c')
	{
		ca = (char)va_arg(args, int);
		write(1, &ca, 1);
	}
	else if (c == '%')
		write(1, "%", 1);
	return (1);
}
