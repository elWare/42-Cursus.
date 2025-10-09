/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:58:06 by jumarque          #+#    #+#             */
/*   Updated: 2024/09/20 08:59:30 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	len_tofind;

	if (*to_find == '\0')
		return ((char *)str);
	len_tofind = ft_strlen(to_find);
	while (*str != '\0' && 0 < n && n >= len_tofind)
	{
		if (*str == *to_find)
		{
			if (ft_strncmp(str, to_find, len_tofind) == 0)
				return ((char *)str);
		}
		str++;
		n--;
	}
	return (NULL);
}
