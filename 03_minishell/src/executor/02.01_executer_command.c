/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.01_executer_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:52:44 by emcorona          #+#    #+#             */
/*   Updated: 2025/08/26 13:45:02 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	ft_putstr_common(char *command, char *message_str);

void	execute_command(t_shell *shell, t_cmd *cmd)
{
	int		i;
	char	*path;
	char	**env;

	i = 0;
	env = shell->environment;
	if (!cmd->args || !cmd->args[0] || cmd->args[0][0] == '\0')
		exit(0);
	while (env[i] && ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	if (!ft_strchr(cmd->args[0], '/') && !(env[i]))
	{
		ft_putendl_fd("No PATH found", STDERR_FILENO);
		exit(127);
	}
	path = ft_path((env[i]), cmd->args);
	handle_command_execution(shell, cmd, path);
	if (path)
		free(path);
}

char	*ft_path(char *path, char **comm)
{
	char	**paths;

	if (ft_strchr(comm[0], '/'))
	{
		if (access(comm[0], F_OK | X_OK) == 0)
			return (ft_strdup(comm[0]));
		return (NULL);
	}
	if (!path)
		return (NULL);
	paths = ft_split(path + 5, ':');
	return (search_in_paths(paths, comm[0]));
}

char	*search_in_paths(char **paths, char *comm)
{
	char	*route;
	char	*tmp;
	int		i;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		route = ft_strjoin(tmp, comm);
		free(tmp);
		if (access(route, F_OK | X_OK) == 0)
		{
			free_matrix(paths);
			return (route);
		}
		free(route);
		i++;
	}
	free_matrix(paths);
	return (NULL);
}

void	handle_command_execution(t_shell *shell, t_cmd *cmd, char *path)
{
	int	errno;

	errno = 127;
	if (!path)
	{
		if (access(cmd->args[0], X_OK) != 0 && access(cmd->args[0], F_OK) == 0
			&& ft_strchr(cmd->args[0], '/'))
		{
			ft_putstr_common(cmd->args[0], "': Permission denied");
			errno = 126;
		}
		else if (!ft_strchr(cmd->args[0], '/'))
			ft_putstr_common(cmd->args[0], "': command not found");
		else
			ft_putstr_common(cmd->args[0], "': No such file or directory");
		free_matrix(cmd->args);
		exit(errno);
	}
	execve(path, cmd->args, shell->environment);
	free_matrix(cmd->args);
	free(path);
	ft_putendl_fd(" Is a directory", STDERR_FILENO);
	exit(126);
}

static void	ft_putstr_common(char *command, char *message_str)
{
	ft_putstr_fd("minishell: `", STDERR_FILENO);
	ft_putstr_fd(command, STDERR_FILENO);
	ft_putendl_fd(message_str, STDERR_FILENO);
}
