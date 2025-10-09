/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:48:53 by qmuntada          #+#    #+#             */
/*   Updated: 2025/03/21 10:09:34 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	if (s && n > 0)
	{
		while (i < n)
		{
			if (p[i] == (unsigned char)c)
				return ((void *)(p + i));
			i++;
		}
	}
	return (NULL);
}
