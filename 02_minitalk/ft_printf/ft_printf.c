/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:20:21 by jumarque          #+#    #+#             */
/*   Updated: 2024/10/21 15:32:06 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int	ft_print(unsigned char c, va_list args)
{
	int		result;

	if (c == 'i' || c == 'd' || c == 'u')
		result = ft_printdiu(c, args);
	else if (c == 's')
		result = ft_prints(args);
	else if (c == 'c' || c == '%')
		result = ft_printc(c, args);
	else if (c == 'x' || c == 'X')
		result = ft_printhex(c, args);
	else if (c == 'p')
		result = ft_printptr(args);
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			len;

	if (!format)
		return (0);
	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%' && ft_strchr(TYPE_FORMAT, *(format + 1)))
		{
			format++;
			len += ft_print(*format, args);
		}
		else
		{
			len += write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return (len);
}

/*int main(void)
{
	int	numb;
	
	numb = printf(" %p %p ", 0, 0);
	printf("\nCaracteres: %i\n", numb);
	ft_printf(" %p %p ", 0, 0);
	numb = printf("\nCaracteres: %i\n", numb);
	return (0);
}*/
