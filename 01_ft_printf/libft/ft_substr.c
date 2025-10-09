/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:36:40 by jumarque          #+#    #+#             */
/*   Updated: 2024/09/23 15:18:53 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr_substr;
	int		i_substr;

	if (s != NULL)
	{
		if (start > ft_strlen(s))
			return (ft_strdup(""));
		if (len > ft_strlen(s + start))
			len = ft_strlen(s + start);
		ptr_substr = ft_calloc(len + 1, 1);
		if (ptr_substr == NULL)
			return (NULL);
		i_substr = 0;
		while ((size_t)i_substr < len && s[start] != '\0')
		{
			ptr_substr[i_substr] = s[start];
			i_substr++;
			start++;
		}
		return (ptr_substr);
	}
	return (NULL);
}
