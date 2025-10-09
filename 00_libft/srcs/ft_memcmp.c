/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:24:17 by jumarque          #+#    #+#             */
/*   Updated: 2024/09/17 10:22:34 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str_s1;
	unsigned char	*str_s2;

	if (n == 0)
		return (0);
	str_s1 = (unsigned char *)s1;
	str_s2 = (unsigned char *)s2;
	while (0 < n--)
	{
		if (*str_s1 != *str_s2)
			return (*str_s1 - *str_s2);
		str_s1++;
		str_s2++;
	}
	return (0);
}
