/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:45:21 by qmuntada          #+#    #+#             */
/*   Updated: 2025/03/21 10:01:20 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	length;
	size_t	index;

	length = ft_strlen(src);
	index = -1;
	while (++index <= length && src[index] != '\0')
		*(dst + index) = *(src + index);
	dst[index] = '\0';
	return (dst);
}
