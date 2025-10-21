/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_utils_builtins_00.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:03:10 by emcorona          #+#    #+#             */
/*   Updated: 2025/08/11 11:58:45 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_mtrx_size(char **mtrx)
{
	int	i;

	i = 0;
	while (mtrx && mtrx[i])
		i++;
	return (i);
}

int	ft_search_index_env(char **env, char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (env && env[i])
	{
		if (ft_strncmp(env[i], str, len) == 0
			&& (env[i][len] == '='
			|| env[i][len] == '\0'))
			return (i);
		i++;
	}
	return (-1);
}

int	ft_valid_env_var(char *env_var)
{
	int	i;

	if (!env_var || (env_var[0] != '_' && !ft_isalpha(env_var[0])))
		return (0);
	i = 1;
	while (env_var[i] && env_var[i] != '=')
	{
		if (env_var[i] != '_' && env_var[i] != '+' && !ft_isalnum(env_var[i]))
			return (0);
		if (env_var[i] == '+' && env_var[i + 1] == '='
			&& env_var[i - 1] && ft_isalnum(env_var[i - 1]))
			return (2);
		i++;
	}
	return (1);
}

char	**ft_copy_mtrx(char **mtrx)
{
	char	**new_mtrx;
	int		i;
	int		len_mtrx;

	i = 0;
	if (!mtrx)
		return (NULL);
	len_mtrx = ft_mtrx_size(mtrx);
	new_mtrx = (char **)malloc(sizeof(char *) * (len_mtrx + 1));
	if (!new_mtrx)
		return (NULL);
	while (mtrx[i])
	{
		new_mtrx[i] = ft_strdup(mtrx[i]);
		if (!new_mtrx[i])
		{
			free_matrix(new_mtrx);
			return (NULL);
		}
		i++;
	}
	new_mtrx[i] = NULL;
	return (new_mtrx);
}

void	ft_swap_mtrx(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}
