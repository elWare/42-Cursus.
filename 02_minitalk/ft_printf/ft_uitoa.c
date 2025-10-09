/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 08:41:15 by jumarque          #+#    #+#             */
/*   Updated: 2024/10/21 15:19:19 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void	ft_conv(unsigned int n, char *pos)
{
	if (n >= 10)
	{
		ft_conv(n / 10, pos - 1);
	}
	*pos = (n % 10) + '0';
}

static unsigned int	ft_intlen(unsigned int n)
{
	unsigned int	len;

	len = 1;
	while (n >= 10)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned int	len_int;
	char			*ptr_str;

	if (n == 0)
	{
		ptr_str = ft_strdup("0");
		return (ptr_str);
	}
	len_int = ft_intlen(n);
	ptr_str = ft_calloc(len_int + 1, sizeof(char));
	if (ptr_str == NULL)
		return (NULL);
	ptr_str[len_int] = '\0';
	ft_conv(n, ptr_str + len_int - 1);
	return (ptr_str);
}
