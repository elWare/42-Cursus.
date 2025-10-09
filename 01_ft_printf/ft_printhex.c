/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:44:56 by jumarque          #+#    #+#             */
/*   Updated: 2025/03/13 14:56:23 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int	ft_hexlen(unsigned int numb)
{
	int	len;

	len = 0;
	while (numb)
	{
		numb /= 16;
		len++;
	}
	return (len);
}

int	ft_printhex(unsigned char c, va_list args)
{
	int				len;
	unsigned int	hex_num;
	char			*hex_str;

	hex_num = va_arg(args, unsigned int);
	if (hex_num == 0)
		return (write(1, "0", 1));
	len = ft_hexlen(hex_num);
	hex_str = ft_calloc(len + 1, sizeof(char));
	hex_str[len] = '\0';
	while (len > 0)
	{
		hex_str[--len] = "0123456789abcdef"[hex_num % 16];
		hex_num /= 16;
	}
	len = write(1, hex_str, ft_strlen(hex_str));
	free (hex_str);
	return (len);
}
