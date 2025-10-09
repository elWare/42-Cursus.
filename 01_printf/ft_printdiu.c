/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdiu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:58:11 by jumarque          #+#    #+#             */
/*   Updated: 2025/03/13 14:52:53 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printdiu(unsigned char c, va_list args)
{
	char			*str;
	int				len;
	unsigned int	un;

	un = va_arg(args, unsigned int);
	str = ft_itoa(un);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
