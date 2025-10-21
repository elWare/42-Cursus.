/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:56:34 by juagomez          #+#    #+#             */
/*   Updated: 2025/08/26 14:16:29 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, unsigned int len)
{
	unsigned int	str_len;
	unsigned int	substr_index;
	unsigned char	*substr;

	str_len = ft_strlen(str);
	substr_index = 0;
	if (!str)
		return (NULL);
	if (start > str_len)
		return (ft_strdup(""));
	if ((start + len) > str_len)
		len = str_len - start;
	substr = malloc(sizeof(unsigned char) * (len + 1));
	if (!substr)
		return (NULL);
	while (substr_index < len)
	{
		substr[substr_index] = str[start + substr_index];
		substr_index++;
	}
	substr[substr_index] = '\0';
	return ((char *)substr);
}
