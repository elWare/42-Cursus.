/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 08:41:15 by jumarque          #+#    #+#             */
/*   Updated: 2024/09/27 12:09:51 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_conv(int n, char *pos)
{
	if (n >= 10)
	{
		ft_conv(n / 10, pos - 1);
	}
	*pos = (n % 10) + '0';
}

static int	ft_intlen(int n)
{
	int	len;

	if (n < 0)
		n = n * -1;
	len = 1;
	while (n >= 10)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ptr_str;
	int		len_int;
	int		negativo;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len_int = ft_intlen(n);
	negativo = (n < 0) + 1;
	ptr_str = ft_calloc(len_int + negativo, sizeof(char));
	if (ptr_str == NULL)
		return (NULL);
	if (n >= 0)
	{
		ft_conv(n, ptr_str + len_int - 1);
		return (ptr_str);
	}
	else
	{
		ptr_str[0] = '-';
		ft_conv(-1 * n, ptr_str + len_int);
		return (ptr_str);
	}
}
