/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05.1_expand_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:20:15 by juagomez          #+#    #+#             */
/*   Updated: 2025/08/19 11:48:13 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	extract_single_variable(char *raw_token, int start_index);
int			last_exit_status_expander(t_token *token, int first_index);
int			literal_expander(t_token *token, int first_index, bool success);

int	basic_expander(t_token *token, int index)
{
	t_expand		*expand_node;
	t_data_token	d_token;
	bool			success;

	d_token.token_len = extract_single_variable(token->raw_token, index);
	d_token.rw_word = ft_substr(token->raw_token, index, d_token.token_len);
	expand_node = add_expand_node(&token->expands_list, d_token.rw_word,
			index, BASIC_EXPANSION);
	expand_node->key = ft_strdup(extract_key(d_token.rw_word, 1));
	expand_node->last_index = index + d_token.token_len - 1;
	success = true;
	if (!token || d_token.token_len <= 0
		|| !d_token.rw_word || !expand_node
		|| !expand_node->key)
		success = false;
	free(d_token.rw_word);
	if (success)
		return (d_token.token_len);
	ft_putendl_fd(ERROR_INVALID_INPUT, STDERR_FILENO);
	return (FAILURE);
}

static int	extract_single_variable(char *raw_token, int start_index)
{
	int	index;

	if (!raw_token || !is_expansion_char(raw_token[start_index]))
		return (0);
	index = start_index + 1;
	if (is_space(raw_token[index]) || !raw_token[index])
		return (1);
	if (raw_token[index] == '?')
		return (2);
	if (!ft_isalpha(raw_token[index]) && raw_token[index] != '_')
		return (1);
	while ((ft_isalnum(raw_token[index]) || raw_token[index] == '_')
		&& raw_token[index])
		index++;
	return (index - start_index);
}

int	last_exit_status_expander(t_token *token, int first_index)
{
	t_expand	*expand_node;
	char		*substitution_str;
	int			len_input;

	if (!token)
		return (ft_putendl_fd(ERROR_INVALID_INPUT, STDERR_FILENO), FAILURE);
	substitution_str = ft_strdup("$?");
	if (!substitution_str)
		return (ft_putendl_fd(ERR_MEM_ALLOC, STDERR_FILENO), FAILURE);
	len_input = ft_strlen(substitution_str);
	expand_node = add_expand_node(&token->expands_list, substitution_str,
			first_index, LAST_EXIT_STATUS);
	expand_node->key = ft_strdup("$?");
	if (!expand_node->key)
	{
		free(substitution_str);
		return (ft_putendl_fd(ERR_MEM_ALLOC, STDERR_FILENO), FAILURE);
	}
	free(substitution_str);
	return (len_input);
}

int	curly_braces_expander(t_token *tkn, int fts_i, bool success)
{
	t_expand		*expand_node;
	int				end_i;
	char			*key_temp;
	t_data_token	d_tkn;

	end_i = fts_i + 2;
	while (tkn && tkn->raw_token[end_i] && tkn->raw_token[end_i] != '}')
		end_i++;
	if (tkn->raw_token[end_i] == '}')
	{
		d_tkn.rw_word = ft_substr(tkn->raw_token, fts_i, (end_i - fts_i + 1));
		d_tkn.token_len = ft_strlen(d_tkn.rw_word);
		expand_node = add_expand_node(&tkn->expands_list, d_tkn.rw_word, fts_i,
				CURLY_BRACES);
		key_temp = extract_key(d_tkn.rw_word, 1);
		expand_node->key = ft_strdup(ft_strtrim(key_temp, "{}"));
		expand_node->last_index = fts_i + d_tkn.token_len - 1;
	}
	if (!tkn || !d_tkn.rw_word || !key_temp || !expand_node->key)
		success = false;
	free(d_tkn.rw_word);
	if (success)
		return (d_tkn.token_len);
	return (ft_putendl_fd(ERR_MEM_ALLOC, STDERR_FILENO), FAILURE);
}

int	literal_expander(t_token *token, int index, bool success)
{
	t_expand	*expand_node;
	char		*substitution_str;
	int			len_input;
	char		*key;
	int			first_index;

	if (!token)
		return (ft_putendl_fd(ERROR_INVALID_INPUT, STDERR_FILENO), FAILURE);
	first_index = index - 1;
	len_input = extract_single_variable(token->raw_token, first_index + 1);
	substitution_str = ft_substr(token->raw_token, first_index, len_input + 1);
	expand_node = add_expand_node(&token->expands_list, substitution_str,
			first_index, LITERAL);
	key = ft_substr(substitution_str, 1, ft_strlen(substitution_str) - 1);
	expand_node->key = ft_strdup(key);
	if (!expand_node->key || !substitution_str || !expand_node || !key)
		success = false;
	expand_node->last_index = index + len_input - 1;
	free(key);
	free(substitution_str);
	if (success)
		return (len_input);
	return (ft_putendl_fd(ERR_MEM_ALLOC, STDERR_FILENO), FAILURE);
}
