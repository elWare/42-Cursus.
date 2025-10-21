/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_execute_shell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:35:28 by juagomez          #+#    #+#             */
/*   Updated: 2025/08/28 10:52:32 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	execute_shell(t_shell *shell)
{
	if (!shell)
		return (ft_putendl_fd(ERROR_INVALID_INPUT, STDERR_FILENO), FAILURE);
	while (1)
	{
		if (read_user_input(shell, PROMPT, NULL) == FAILURE)
			break ;
		if (process_input(shell) == FAILURE)
		{
			free_iteration_input(shell);
			continue ;
		}
		free_iteration_input(shell);
	}
	free_iteration_input(shell);
	return (SUCCESS);
}

int	read_user_input(t_shell *shell, char *prompt, char *input)
{
	shell->last_exit_status = shell->exit_status;
	setup_signals();
	input = readline(prompt);
	if (!input)
		return (ft_putendl_fd("exit", STDOUT_FILENO), FAILURE);
	if (g_signal_flag)
	{
		shell->exit_status = g_signal_flag;
		shell->last_exit_status = g_signal_flag;
		g_signal_flag = 0;
	}
	else if (!g_signal_flag && shell->last_exit_status == 0)
		shell->exit_status = SUCCESS;
	if (input[0] == '\0')
		return (free(input), SUCCESS);
	shell->input = ft_strdup(input);
	if (!shell->input)
	{
		free(input);
		shell->exit_status = ERROR;
		return (ft_putendl_fd(ERROR_INPUT_READER, STDERR_FILENO), FAILURE);
	}
	return (free(input), SUCCESS);
}

int	process_input(t_shell *shell)
{
	if (!shell || !shell->input)
		return (FAILURE);
	if (validate_syntax(shell) == SYNTAX_ERROR)
		return (FAILURE);
	create_commands_structure(shell);
	if (validate_command_structure(shell) == SYNTAX_ERROR)
		return (FAILURE);
	process_commands(shell);
	if (validate_command_semantics(shell) == SYNTAX_ERROR)
		return (FAILURE);
	build_execution_structure(shell->commands_list, shell);
	if (shell->commands_list)
		exec_commands(shell);
	free_commands_list(&shell->commands_list);
	return (SUCCESS);
}

void	process_commands(t_shell *shell)
{
	t_cmd	*current_command;

	if (!shell)
		return (ft_putendl_fd(ERROR_INVALID_INPUT, STDERR_FILENO));
	current_command = (t_cmd *) shell->commands_list;
	while (current_command)
	{
		lexical_analyzer(current_command, shell);
		tokenizer(current_command->words_list, shell);
		variable_expander(current_command->words_list, shell);
		dequotize_tokens(current_command->words_list, shell);
		generate_processed_word(current_command->words_list, shell);
		current_command = current_command->next;
	}
}
