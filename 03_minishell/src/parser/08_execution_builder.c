/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_execution_builder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 21:44:56 by juagomez          #+#    #+#             */
/*   Updated: 2025/08/27 12:43:38 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	fill_command_arguments(t_cmd *command);
static void	process_redirections(t_cmd *command);
static int	count_word_arguments(t_word *words_list);
static bool	is_builtin_command(char *command);

void	build_execution_structure(t_cmd *commands_list, t_shell *shell)
{
	t_cmd	*current_command;

	current_command = (t_cmd *) commands_list;
	while (current_command)
	{
		fill_command_arguments(current_command);
		process_redirections(current_command);
		if (current_command->exit_status == ERROR)
			shell->exit_status = ERROR;
		else
			shell->exit_status = SUCCESS;
		current_command = current_command->next;
	}
}

static void	fill_command_arguments(t_cmd *command)
{
	int		index;
	int		args_count;
	t_word	*current_word;

	if (!command)
		return (ft_putendl_fd(ERROR_INVALID_INPUT, STDERR_FILENO));
	index = 0;
	current_word = (t_word *) command->words_list;
	args_count = count_word_arguments(current_word);
	if (!command->args)
		command->args = (char **) ft_calloc(sizeof(char *), (args_count + 2));
	else
		while (command->args[index])
			index++;
	ft_proccess_words_list(command, current_word, index);
	if (command->args[0])
		command->is_btn = is_builtin_command(command->args[0]);
}

static void	process_redirections(t_cmd *command)
{
	t_word	*word;

	if (!command)
		return (ft_putendl_fd(ERROR_INVALID_INPUT, STDERR_FILENO));
	word = command->words_list;
	while (word)
	{
		if (word->word_type == OUTFILE && word->next
			&& word->next->word_type == WORD
			&& process_outfile(command, word) == FAILURE)
			break ;
		else if (word->word_type == APPEND && word->next
			&& word->next->word_type == WORD
			&& process_append(command, word) == FAILURE)
			break ;
		else if (word->word_type == INFILE && word->next
			&& word->next->word_type == WORD
			&& process_infile(command, word) == FAILURE)
			break ;
		else if (word->word_type == HERE_DOC && word->next
			&& word->next->word_type == WORD
			&& process_heredoc(command, word) == FAILURE)
			break ;
		word = word->next;
	}
}

static int	count_word_arguments(t_word *words_list)
{
	t_word	*current_word;
	int		args_count;

	if (!words_list)
		return (ft_putendl_fd(ERROR_INVALID_INPUT, STDERR_FILENO), ERROR);
	current_word = (t_word *) words_list;
	args_count = 0;
	while (current_word)
	{
		if (current_word->word_type == WORD)
			args_count++;
		current_word = current_word->next;
	}
	return (args_count);
}

static bool	is_builtin_command(char *command)
{
	bool	is_builtin;

	if (!command)
		return (ft_putendl_fd(ERROR_INVALID_INPUT, STDERR_FILENO), false);
	is_builtin = false;
	if (!ft_strncmp(command, "echo", ft_strlen("echo") + 1))
		is_builtin = true;
	else if (!ft_strncmp(command, "cd", ft_strlen("cd") + 1))
		is_builtin = true;
	else if (!ft_strncmp(command, "pwd", ft_strlen("pwd")))
		is_builtin = true;
	else if (!ft_strncmp(command, "export", ft_strlen("export") + 1))
		is_builtin = true;
	else if (!ft_strncmp(command, "unset", ft_strlen("unset") + 1))
		is_builtin = true;
	else if (!ft_strncmp(command, "env", ft_strlen("env") + 1))
		is_builtin = true;
	else if (!ft_strncmp(command, "exit", ft_strlen("exit") + 1))
		is_builtin = true;
	return (is_builtin);
}
