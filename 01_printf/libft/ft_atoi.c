/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:55:32 by jumarque          #+#    #+#             */
/*   Updated: 2024/09/23 12:25:41 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_num(char value_char)
{
	if (value_char >= '0' && value_char <= '9')
		return (1);
	else
		return (0);
}

static int	ft_is_sign(const char c)
{
	if (c == '-')
		return (-1);
	if (c == '+')
		return (1);
	return (0);
}

static int	ft_is_space(const char c)
{
	if ((c >= 9 && 13 >= c) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (ft_is_space(*str))
		str++;
	if (ft_is_sign(*str) != 0)
	{
		sign = ft_is_sign(*str);
		str++;
	}
	while (ft_is_num(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((int)result * sign);
}
