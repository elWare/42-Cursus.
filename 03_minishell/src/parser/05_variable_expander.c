/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_variable_expander.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:21:41 by juagomez          #+#    #+#             */
/*   Updated: 2025/08/25 11:26:01 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	expand_single_token(t_token *token, t_shell *shell);
static void	extract_expansion_nodes(t_token *token, int index);
static void	resolve_expansion_values(t_token *token, t_shell *shell);
static void	insert_expansion_values(t_token *token);

void	variable_expander(t_word *words_list, t_shell *shell)
{
	t_word	*current_word;
	t_token	*current_token;

	if (!words_list || !shell)
		return (ft_putendl_fd(ERROR_INVALID_INPUT, STDERR_FILENO));
	current_word = (t_word *) words_list;
	while (current_word)
	{
		current_token = (t_token *) current_word->tokens_list;
		while (current_token)
		{
			if (expand_single_token(current_token, shell) == FAILURE)
				shell->exit_status = ERROR;
			current_token = current_token->next;
		}
		current_word = current_word->next;
	}
}

static int	expand_single_token(t_token *token, t_shell *shell)
{
	if (!token)
		return (ft_putendl_fd(ERROR_INVALID_INPUT, STDERR_FILENO), FAILURE);
	extract_expansion_nodes(token, 0);
	resolve_expansion_values(token, shell);
	insert_expansion_values(token);
	return (SUCCESS);
}

static void	extract_expansion_nodes(t_token *tkn, int i)
{
	int		subs_len;

	if (!tkn)
		return (ft_putendl_fd(ERROR_INVALID_INPUT, STDERR_FILENO));
	if (tkn->type == SINGLE_QUOTES)
		return ;
	while (tkn->raw_token[i])
	{
		if (is_expansion_char(tkn->raw_token[i]))
		{
			if (!tkn->raw_token[i + 1] || is_space(tkn->raw_token[i + 1])
				|| tkn->raw_token[i + 1] == '"')
				i++;
			else if (tkn->raw_token[i + 1])
			{
				subs_len = subs_len_asign(tkn, i);
				if (subs_len == FAILURE)
					return ;
				i += subs_len;
			}
		}
		else
			i++;
	}
}

static void	resolve_expansion_values(t_token *token, t_shell *shell)
{
	t_expand	*expand_node;
	char		*value;

	if (!token || !shell->environment)
		return (ft_putendl_fd(ERROR_INVALID_INPUT, STDERR_FILENO));
	expand_node = (t_expand *) token->expands_list;
	while (expand_node)
	{
		value = ft_expander(expand_node, shell);
		if (value)
			expand_node->value = value;
		expand_node = expand_node->next;
	}
}

static void	insert_expansion_values(t_token *token)
{
	int	last_position;

	if (!token || !token->expands_list || token->type == SINGLE_QUOTES)
	{
		token->expanded_token = ft_strdup(token->raw_token);
		if (!token->expanded_token)
			return ;
		return ;
	}
	last_position = insert_expand_node_value(token, 0);
	if (token->raw_token[last_position])
		token->expanded_token = ft_strjoin_free(token->expanded_token,
				&token->raw_token[last_position]);
}
