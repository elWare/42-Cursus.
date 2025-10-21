/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.00_executer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:52:36 by emcorona          #+#    #+#             */
/*   Updated: 2025/08/28 10:56:32 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	exec_commands(t_shell *ms)
{
	int		pipefd[2];
	int		prevfd;
	t_cmd	*cmd;
	pid_t	pids[MAX_PIDS];
	int		i;

	i = 0;
	cmd = ms->commands_list;
	prevfd = -1;
	add_history(ms->input);
	if (cmd->is_btn && !cmd->next && (prevfd == -1))
	{
		exec_builtins(ms, cmd, prevfd);
		return ;
	}
	while (cmd)
	{
		pids[i] = exec_single_cmd(cmd, &prevfd, pipefd, ms);
		cmd = cmd->next;
		i++;
	}
	wait_all_processes(pids, ms);
}

pid_t	exec_single_cmd(t_cmd *cmd, int *prevfd, int *pipefd, t_shell *ms)
{
	pid_t	pid;

	if (cmd->next && pipe(pipefd) == -1)
	{
		perror("Error creating pipe\n");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error creating child process.\n");
		exit(1);
	}
	if (pid == 0)
		child_process(cmd, *prevfd, pipefd, ms);
	else
	{
		parent_process(ms, prevfd, pipefd);
		if (cmd->is_btn && !ft_strncmp(cmd->args[0], "exit", 5)
			&& (*prevfd == -1))
			exit(ms->exit_status);
	}
	return (pid);
}

void	child_process(t_cmd *cmd, int prevfd, int pipefd[2], t_shell *ms)
{
	if (redirections(ms, cmd) == 1)
		exit (1);
	if (prevfd != -1 && !cmd->infile)
		dup2(prevfd, STDIN_FILENO);
	if (cmd->next && !cmd->outfile)
		dup2(pipefd[1], STDOUT_FILENO);
	if (prevfd != -1)
		close(prevfd);
	if (cmd->next)
	{
		close(pipefd[0]);
		close(pipefd[1]);
	}
	signal(SIGQUIT, ft_handle_sigquit);
	if (cmd->is_btn)
	{
		exec_builtins(ms, cmd, prevfd);
		exit(ms->exit_status);
	}
	else
		execute_command(ms, cmd);
	ft_putendl_fd("Error child process", STDERR_FILENO);
	exit (126);
}

void	parent_process(t_shell *ms, int *prevfd, int pipefd[2])
{
	if (*prevfd != -1)
		close(*prevfd);
	if (ms->commands_list->next)
	{
		close(pipefd[1]);
		*prevfd = pipefd[0];
	}
	else
		*prevfd = -1;
	g_signal_flag = 1;
	signal(SIGQUIT, ft_handle_sigquit);
}

void	wait_all_processes(pid_t *pids, t_shell *shell)
{
	int		status;
	int		i;
	t_cmd	*cmd;

	i = 0;
	cmd = shell->commands_list;
	while (cmd)
	{
		waitpid(pids[i], &status, 0);
		i++;
		if (!cmd->next)
			ft_check_exitstat(status, shell);
		cmd = cmd->next;
	}
}
