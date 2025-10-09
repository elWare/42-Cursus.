/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:00:12 by jumarque          #+#    #+#             */
/*   Updated: 2024/09/20 13:00:22 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_isoverflow(size_t l1, size_t l2)
{
	size_t	mid_max;
	size_t	mid_join;

	mid_max = __SIZE_MAX__ / 2;
	mid_join = ((l1 / 2) + (l2 / 2));
	if (mid_join <= mid_max)
		return (0);
	return (1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*ptr_strjoin;
	int		i;
	int		j;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (ft_isoverflow(len_s1, len_s2 + 1) == 1)
		return (NULL);
	ptr_strjoin = malloc (len_s1 + len_s2 + 1);
	if (ptr_strjoin == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		ptr_strjoin[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		ptr_strjoin[j++] = s2[i++];
	ptr_strjoin [j] = 0;
	return (ptr_strjoin);
}
