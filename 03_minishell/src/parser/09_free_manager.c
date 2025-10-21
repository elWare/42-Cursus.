/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_free_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:31:55 by juagomez          #+#    #+#             */
/*   Updated: 2025/08/12 12:21:08 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_commands_list(t_cmd **commands_list);
void	free_words_list(t_word **words_list);
void	free_tokens_list(t_token **token_list);
void	free_expands_list(t_expand **expands_list);

void	free_iteration_input(t_shell *shell)
{
	if (shell->input)
	{
		free(shell->input);
		shell->input = NULL;
	}
	if (shell->commands_list)
		free_commands_list(&shell->commands_list);
}

void	free_commands_list(t_cmd **commands_list)
{
	t_cmd	*current_node;
	t_cmd	*next_node;

	if (!commands_list)
		return ;
	current_node = (t_cmd *) *commands_list;
	while (current_node)
	{
		next_node = current_node->next;
		free_matrix(current_node->args);
		if (current_node->command)
			free(current_node->command);
		if (current_node->infile)
			free(current_node->infile);
		if (current_node->outfile)
			free(current_node->outfile);
		if (current_node->delimiter)
			free(current_node->delimiter);
		if (current_node->words_list)
			free_words_list(&current_node->words_list);
		free(current_node);
		current_node = next_node;
	}
	*commands_list = NULL;
}

void	free_words_list(t_word **words_list)
{
	t_word	*current_node;
	t_word	*next_node;

	if (!words_list)
		return ;
	current_node = (t_word *) *words_list;
	while (current_node)
	{
		next_node = current_node->next;
		if (current_node->raw_word)
			free(current_node->raw_word);
		if (current_node->processed_word)
			free(current_node->processed_word);
		if (current_node->tokens_list)
			free_tokens_list(&current_node->tokens_list);
		free(current_node);
		current_node = next_node;
	}
	*words_list = NULL;
}

void	free_tokens_list(t_token **tokens_list)
{
	t_token	*current_node;
	t_token	*next_node;

	if (!tokens_list)
		return ;
	current_node = (t_token *) *tokens_list;
	while (current_node)
	{
		next_node = current_node->next;
		if (current_node->raw_token)
			free(current_node->raw_token);
		if (current_node->expanded_token)
			free(current_node->expanded_token);
		if (current_node->noquotes_token)
			free(current_node->noquotes_token);
		if (current_node->expands_list)
			free_expands_list(&current_node->expands_list);
		free(current_node);
		current_node = next_node;
	}
	*tokens_list = NULL;
}

void	free_expands_list(t_expand **expands_list)
{
	t_expand	*current_node;
	t_expand	*next_node;

	if (!expands_list || !*expands_list)
		return ;
	current_node = (t_expand *) *expands_list;
	while (current_node)
	{
		next_node = current_node->next;
		if (current_node->substitution_str)
			free(current_node->substitution_str);
		if (current_node->key)
			free(current_node->key);
		if (current_node->value)
			free(current_node->value);
		free(current_node);
		current_node = next_node;
	}
	*expands_list = NULL;
}
