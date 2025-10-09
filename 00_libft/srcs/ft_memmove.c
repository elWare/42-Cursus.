/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:25:58 by jumarque          #+#    #+#             */
/*   Updated: 2024/09/18 11:32:48 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fillr(unsigned char *dest, unsigned char *src, int dir, size_t n)
{
	size_t	index;

	if (0 > dir)
	{
		while (0 < n)
		{
			dest[n - 1] = src[n - 1];
			n--;
		}
	}
	if (0 <= dir)
	{
		index = 0;
		while (index < n)
		{
			dest[index] = src[index];
			index++;
		}
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src_ptr;
	unsigned char	*dest_ptr;	

	if (dest == src)
		return (dest);
	src_ptr = (unsigned char *)src;
	dest_ptr = (unsigned char *)dest;
	if (dest_ptr > src_ptr)
	{
		ft_fillr(dest_ptr, src_ptr, -1, n);
	}
	if (dest_ptr < src_ptr)
	{
		ft_fillr(dest_ptr, src_ptr, 1, n);
	}
	return (dest);
}
