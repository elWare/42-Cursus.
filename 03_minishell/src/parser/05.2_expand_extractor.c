/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05.2_expand_extractor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:29:59 by juagomez          #+#    #+#             */
/*   Updated: 2025/08/19 11:44:48 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*extract_key(char *token, int first_index);
char	*get_environment_var(char **env, char *variable);

char	*extract_key(char *token, int first_index)
{
	char	*key;
	int		index;

	if (!token)
		return (ft_putendl_fd(ERROR_INVALID_INPUT, STDERR_FILENO), NULL);
	index = first_index;
	while (!is_space(token[index])
		&& !is_redirection(token[index])
		&& !is_pipe(token[index])
		&& !is_quote(token[index])
		&& !is_expansion_char(token[index])
		&& token[index])
		index++;
	key = ft_substr(token, first_index, (index - first_index));
	if (!key)
		return (ft_putendl_fd(ERR_MEM_ALLOC, STDERR_FILENO), NULL);
	return (key);
}

char	*get_environment_var(char **env, char *variable)
{
	char	*value;
	int		index;
	int		match;

	if (!env || !variable)
		return (ft_putendl_fd(ERROR_INVALID_INPUT, STDERR_FILENO), NULL);
	value = NULL;
	index = 0;
	match = 0;
	while (env[index])
	{
		match = ft_strncmp(env[index], variable, ft_strlen(variable));
		if (!match && env[index][ft_strlen(variable)] == '=')
		{
			value = ft_strdup(&env[index][ft_strlen(variable) + 1]);
			return (value);
		}
		index++;
	}
	return (NULL);
}

char	*ft_expander(t_expand *expand_node, t_shell *shell)
{
	char	*value;

	if (expand_node->type == LAST_EXIT_STATUS)
	{
		value = ft_itoa(shell->exit_status);
		if (!value)
			return (NULL);
	}
	else if (expand_node->type == CURLY_BRACES)
		value = get_environment_var(shell->environment, expand_node->key);
	else if (expand_node->type == LITERAL)
	{
		value = ft_strdup(expand_node->key);
		if (!value)
			return (NULL);
	}
	else
		value = get_environment_var(shell->environment, expand_node->key);
	return (value);
}

int	subs_len_asign(t_token *tkn, int i)
{
	int	subs_len;

	if (tkn->raw_token[i + 1] == '?')
		subs_len = last_exit_status_expander(tkn, i);
	else if (i > 0 && tkn->raw_token[i - 1] == '\\')
		subs_len = literal_expander(tkn, i, true);
	else if (tkn->raw_token[i + 1] == '{')
		subs_len = curly_braces_expander(tkn, i, true);
	else
		subs_len = basic_expander(tkn, i);
	return (subs_len);
}
