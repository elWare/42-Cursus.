/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:43:40 by jumarque          #+#    #+#             */
/*   Updated: 2024/09/17 10:24:47 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr_found;
	unsigned char	char_tofind;

	char_tofind = (unsigned char)c;
	ptr_found = (unsigned char *)s;
	while (0 < n--)
	{
		if (*ptr_found == char_tofind)
			return ((void *)ptr_found);
		ptr_found++;
	}
	return (NULL);
}
