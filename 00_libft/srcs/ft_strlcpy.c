/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:36:28 by jumarque          #+#    #+#             */
/*   Updated: 2024/09/23 13:30:58 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	leng;

	leng = ft_strlen(src);
	if (leng + 1 < size)
	{
		ft_memcpy(dst, src, leng + 1);
	}
	else if (size != 0)
	{
		ft_memcpy(dst, src, size -1);
		dst[size - 1] = '\0';
	}
	return (leng);
}
