/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03.01_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:53:04 by emcorona          #+#    #+#             */
/*   Updated: 2025/08/11 12:10:08 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*expand_heredoc(char *buffer, char **env, int exit_st)
{
	char	*aux;
	char	*result;
	char	*temp;
	int		i;

	result = ft_strdup("");
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '$' && buffer[i + 1] && (ft_isalpha(buffer[i + 1])
				|| buffer[i + 1] == '_' || buffer[i + 1] == '?'))
			aux = expand_variable(&i, buffer, env, exit_st);
		else
			aux = not_expand(&i, buffer);
		temp = ft_strjoin(result, aux);
		free(result);
		free(aux);
		result = temp;
	}
	return (free(buffer), result);
}

char	*expand_variable(int *i, char *buffer, char **env, int exit_st)
{
	int		start;
	char	*var;
	char	*value;

	(*i)++;
	if (buffer[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(exit_st));
	}
	start = *i;
	while (buffer[*i] && (buffer[*i] == '_' || ft_isalnum(buffer[*i])))
		(*i)++;
	if (start == *i)
		return (ft_strdup("$"));
	var = ft_substr_malloc(buffer, start, (*i) - start + 1);
	value = get_environment_var(env, var);
	free(var);
	if (!value)
		return (ft_strdup(""));
	return (value);
}

char	*not_expand(int *i, char *buffer)
{
	int	start;

	start = *i;
	while (buffer[*i] && buffer[*i] != '$')
		(*i)++;
	if (buffer[*i] == '$')
	{
		if (!buffer[*i + 1])
			(*i)++;
		else if (buffer[*i + 1] && !(ft_isalpha(buffer[*i + 1])
				|| buffer[*i + 1] == '_' || buffer[*i + 1] == '?'))
			buffer[*i] = '\0';
	}
	return (ft_substr_malloc(buffer, start, (*i) - start + 1));
}
