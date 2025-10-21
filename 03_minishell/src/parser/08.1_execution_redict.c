/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08.1_execution_redict.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:16:26 by juagomez          #+#    #+#             */
/*   Updated: 2025/08/19 12:18:21 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	process_infile(t_cmd *command, t_word *word)
{
	if (command->infile)
		free(command->infile);
	command->infile = ft_strdup(word->next->processed_word);
	if (!command->infile)
		return (FAILURE);
	if (access(command->infile, R_OK) == FAILURE)
	{
		command->exit_status = ERROR;
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(command->infile, STDERR_FILENO);
		ft_putendl_fd(ERROR_FILE_NOT_FOUND, STDERR_FILENO);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	process_outfile(t_cmd *command, t_word *word)
{
	int	fd;

	if (command->outfile)
		free(command->outfile);
	command->outfile = ft_strdup(word->next->processed_word);
	if (!command->outfile)
		return (FAILURE);
	command->append = false;
	fd = open(command->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == FAILURE)
	{
		command->exit_status = ERROR;
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(command->outfile, STDERR_FILENO);
		ft_putendl_fd(ERROR_PERMISSION_DENIED, STDERR_FILENO);
		return (FAILURE);
	}
	else if (close(fd) == FAILURE)
	{
		command->exit_status = ERROR;
		ft_putendl_fd(ERROR_CLOSING_FILE, STDERR_FILENO);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	process_append(t_cmd *command, t_word *word)
{
	int	fd;

	if (command->outfile)
		free(command->outfile);
	command->outfile = ft_strdup(word->next->processed_word);
	if (!command->outfile)
		return (FAILURE);
	command->append = true;
	fd = open(command->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == FAILURE)
	{
		command->exit_status = ERROR;
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(command->outfile, STDERR_FILENO);
		ft_putendl_fd(ERROR_PERMISSION_DENIED, STDERR_FILENO);
		return (FAILURE);
	}
	else if (close(fd) == FAILURE)
	{
		command->exit_status = ERROR;
		ft_putendl_fd(ERROR_CLOSING_FILE, STDERR_FILENO);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	process_heredoc(t_cmd *command, t_word *word)
{
	if (command->delimiter)
		free(command->delimiter);
	command->delimiter = ft_strdup(word->next->processed_word);
	if (!command->delimiter)
		return (FAILURE);
	command->hd = true;
	return (SUCCESS);
}
