/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:57:31 by qmuntada          #+#    #+#             */
/*   Updated: 2025/03/21 10:03:52 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1[i])
	{
		while (s1[i] == s2[j])
		{
			i++;
			j++;
			if (!s2[j])
				return ((char *)s1 + (i - ft_strlen(s2)));
		}
		j = 0;
		i++;
	}
	return (NULL);
}
