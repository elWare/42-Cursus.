/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:21:26 by jumarque          #+#    #+#             */
/*   Updated: 2024/09/27 11:24:21 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_findend(char const *str, char const *set);
static int	ft_findbegin(char const *str, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*r_ptr;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = ft_findbegin(s1, set);
	end = ft_findend(s1, set);
	if (start > end)
		return (ft_strdup(""));
	r_ptr = malloc(((end - start) + 2));
	if (r_ptr == NULL)
		return (NULL);
	ft_strlcpy(r_ptr, &s1[start], end - start + 2);
	return (r_ptr);
}

static int	ft_findbegin(char const *str, char const *set)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr(set, str[i]))
		i++;
	return (i);
}

static int	ft_findend(char const *str, char const *set)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && ft_strchr(set, str[i]))
		i--;
	return (i);
}
