/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 08:33:39 by jumarque          #+#    #+#             */
/*   Updated: 2024/09/27 13:03:02 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_cpycstr(char const *str, int *start, char c);
static int	ft_nstr(char const *s, char c);
static void	ft_free(char **str_ptr, int count);

char	**ft_strsplit(char const *s, char c)
{
	int		i_s;
	int		str_count;
	char	**ptr_split;
	int		i_ptr;

	if (s == NULL)
		return (NULL);
	str_count = ft_nstr(s, c);
	ptr_split = ft_calloc((str_count + 1), sizeof(char *));
	if (ptr_split == NULL)
		return (NULL);
	i_ptr = 0;
	i_s = 0;
	while (i_ptr < str_count)
	{
		ptr_split[i_ptr] = ft_cpycstr(s, &i_s, c);
		if (ptr_split[i_ptr] == NULL)
		{
			ft_free(ptr_split, i_ptr);
			return (NULL);
		}
		i_ptr++;
	}
	ptr_split[i_ptr] = NULL;
	return (ptr_split);
}

static int	ft_nstr(char const *s, char c)
{
	int	i_s;
	int	str_count;
	int	in_string;

	str_count = 0;
	i_s = 0;
	in_string = 0;
	while (s[i_s] != '\0')
	{
		if (s[i_s] != c && !in_string)
		{
			in_string = 1;
			str_count++;
		}
		else if (s[i_s] == c)
		{
			in_string = 0;
		}
		i_s++;
	}
	return (str_count);
}

static char	*ft_cpycstr(char const *str, int *start, char c)
{
	int		len;
	int		index;
	char	*ptr_str;

	index = *start;
	len = 0;
	while (str[index] == c && str[index] != '\0')
		index++;
	*start = index;
	while (str[index + len] != c && str[index + len] != '\0')
	{
		len++;
	}
	ptr_str = malloc((len + 1) * sizeof(char));
	if (ptr_str == NULL)
		return (NULL);
	index = 0;
	while ((index < len))
		ptr_str[index++] = str[(*start)++];
	ptr_str[index] = '\0';
	return (ptr_str);
}

static void	ft_free(char **str_ptr, int count)
{
	int	index;

	index = 0;
	while (index < count)
	{
		free(str_ptr[index]);
		index++;
	}
	free(str_ptr);
}
