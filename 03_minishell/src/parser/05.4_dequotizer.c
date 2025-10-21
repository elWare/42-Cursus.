/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05.4_dequotizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:46:05 by juagomez          #+#    #+#             */
/*   Updated: 2025/08/12 12:45:39 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	remove_quotes(t_token *tokens_list);
void		update_quote_state(char character, bool *in_single_quotes,
				bool *in_double_quotes);

void	dequotize_tokens(t_word *words_list, t_shell *shell)
{
	t_word	*current_word;

	if (!words_list || !shell)
		return (ft_putendl_fd(ERROR_INVALID_INPUT, STDERR_FILENO));
	current_word = (t_word *) words_list;
	while (current_word)
	{
		if (remove_quotes(current_word->tokens_list) == FAILURE)
			shell->exit_status = ERROR;
		current_word = current_word->next;
	}
}

static int	remove_quotes(t_token *tokens_list)
{
	t_token	*ptr_token;

	if (!tokens_list)
		return (ft_putendl_fd(ERROR_INVALID_INPUT, STDERR_FILENO), FAILURE);
	ptr_token = (t_token *) tokens_list;
	while (ptr_token)
	{
		if (ptr_token->type == DOUBLE_QUOTES
			|| ptr_token->type == SINGLE_QUOTES)
		{
			ptr_token->noquotes_token = ft_substr(ptr_token->expanded_token, 1,
					ft_strlen(ptr_token->expanded_token) - 2);
			if (!ptr_token->noquotes_token)
				return (ft_putendl_fd(ERR_MEM_ALLOC, STDERR_FILENO), FAILURE);
		}
		else
		{
			ptr_token->noquotes_token = ft_strdup(ptr_token->expanded_token);
			if (!ptr_token->noquotes_token)
				return (ft_putendl_fd(ERR_MEM_ALLOC, STDERR_FILENO), FAILURE);
		}
		ptr_token = ptr_token->next;
	}
	return (SUCCESS);
}

void	update_quote_state(char character, bool *in_single_quotes,
			bool *in_double_quotes)
{
	if (character == '\'' && *in_double_quotes == false)
	{
		if (*in_single_quotes == false)
			*in_single_quotes = true;
		else
			*in_single_quotes = false;
	}
	else if (character == '"' && *in_single_quotes == false)
	{
		if (*in_double_quotes == false)
			*in_double_quotes = true;
		else
			*in_double_quotes = false;
	}
}
