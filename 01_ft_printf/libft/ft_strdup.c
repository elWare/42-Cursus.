/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:50:44 by jumarque          #+#    #+#             */
/*   Updated: 2024/09/23 14:03:47 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	index;
	char	*s_dup;

	len = 0;
	index = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	s_dup = (char *)malloc(len + 1);
	if (s_dup == NULL)
		return (NULL);
	while (index < len)
	{
		s_dup[index] = s[index];
		index++;
	}
	s_dup[index] = '\0';
	return (s_dup);
}
