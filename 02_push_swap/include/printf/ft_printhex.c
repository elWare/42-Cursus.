/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:44:56 by jumarque          #+#    #+#             */
/*   Updated: 2025/01/24 09:26:30 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init_array(unsigned char c, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		str[i] = i + '0';
		i++;
	}
	if (c == 'x')
		j = 'a';
	else
		j = 'A';
	while (i < 16)
	{
		str[i] = j;
		i++;
		j++;
	}
	str[i] = '\0';
}

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
	char			hex_digits[17];
	int				len;
	unsigned int	hex_num;
	char			*hex_str;

	ft_init_array(c, hex_digits);
	hex_num = va_arg(args, unsigned int);
	if (hex_num == 0)
		return (write(1, "0", 1));
	len = ft_hexlen(hex_num);
	hex_str = ft_calloc(len + 1, sizeof(char));
	hex_str[len] = '\0';
	while (len > 0)
	{
		hex_str[--len] = hex_digits[hex_num % 16];
		hex_num /= 16;
	}
	len = write(1, hex_str, ft_strlen(hex_str));
	free (hex_str);
	return (len);
}
