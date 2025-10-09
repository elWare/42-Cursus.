/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdiu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:58:11 by jumarque          #+#    #+#             */
/*   Updated: 2025/01/24 09:26:09 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdiu(unsigned char c, va_list args)
{
	char			*str;
	int				len;
	unsigned int	un;

	un = va_arg(args, unsigned int);
	if (c == 'i' || c == 'd')
	{
		str = ft_itoa(un);
	}
	else
	{
		str = ft_uitoa(un);
	}
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
