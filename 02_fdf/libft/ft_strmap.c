/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:47:34 by qmuntada          #+#    #+#             */
/*   Updated: 2025/03/21 10:03:05 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		j;
	char	*nstr;

	i = -1;
	if (s && f)
	{
		j = ft_strlen((char *)s);
		nstr = (char *)malloc(j * sizeof(char));
		while (*(s + ++i) != '\0')
			nstr[i] = f(*(s + i));
		return (nstr);
	}
	return (NULL);
}
