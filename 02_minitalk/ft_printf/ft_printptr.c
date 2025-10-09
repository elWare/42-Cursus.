/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:44:56 by jumarque          #+#    #+#             */
/*   Updated: 2024/10/21 15:31:35 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void	ft_init_array(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		str[i] = i + '0';
		i++;
	}
	j = 'a';
	while (i < 16)
	{
		str[i] = j;
		i++;
		j++;
	}
	str[i] = '\0';
}

static int	ft_hexlen(unsigned long long numb)
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

int	ft_printptr(va_list args)
{
	char				hex_digits[17];
	int					len;
	unsigned long long	ptr_num;
	char				*hex_str;

	ft_init_array(hex_digits);
	ptr_num = (unsigned long long)va_arg(args, void *);
	if (ptr_num == 0)
		return (write(1, "(nil)", 5));
	len = ft_hexlen(ptr_num);
	hex_str = ft_calloc(len + 1, sizeof(char));
	if (!hex_str)
		return (0);
	hex_str[len] = '\0';
	while (len > 0)
	{
		hex_str[--len] = hex_digits[ptr_num % 16];
		ptr_num /= 16;
	}
	len = write(1, "0x", 2);
	len += write(1, hex_str, ft_strlen(hex_str));
	free (hex_str);
	return (len);
}
