/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 08:26:31 by jumarque          #+#    #+#             */
/*   Updated: 2024/09/26 11:25:18 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr_str;
	unsigned int	index;

	ptr_str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (ptr_str == NULL)
		return (NULL);
	index = 0;
	while (index < (unsigned int)ft_strlen(s))
	{
		ptr_str[index] = (*f)(index, s[index]);
		index++;
	}
	ptr_str[index] = '\0';
	return (ptr_str);
}
