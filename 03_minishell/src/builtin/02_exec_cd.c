/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_exec_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:13:03 by emcorona          #+#    #+#             */
/*   Updated: 2025/08/26 16:20:29 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*ft_generate_pathcd(t_cmd *cmd, t_shell *shell)
{
	char	*path;
	char	*home;

	path = NULL;
	if (cmd->args[1] == NULL || ft_strcmp(cmd->args[1], "") == 0)
		path = get_environment_var(shell->environment, "HOME");
	else if (cmd->args[1][0] == '~')
	{
		home = get_environment_var(shell->environment, "HOME");
		path = ft_strjoin(home, &cmd->args[1][1]);
		free(home);
	}
	else if (ft_strcmp(cmd->args[1], "-") == 0)
		path = get_environment_var(shell->environment, "OLDPWD");
	else
		path = ft_strdup(cmd->args[1]);
	return (path);
}

static void	ft_modify_pwd(t_shell *shell)
{
	char	*old_pwd;
	char	*cwd;
	char	*pwd;

	pwd = get_environment_var(shell->environment, "PWD");
	old_pwd = ft_strjoin("OLDPWD=", pwd);
	free(pwd);
	cwd = getcwd(NULL, 0);
	pwd = ft_strjoin("PWD=", cwd);
	shell->environment = ft_add_modify_env(shell->environment, old_pwd,
			ft_valid_env_var(old_pwd));
	shell->environment = ft_add_modify_env(shell->environment, pwd,
			ft_valid_env_var(pwd));
	free(pwd);
	free(cwd);
	free(old_pwd);
}

int	exec_cd(t_cmd *cmd, t_shell *shell)
{
	char	*path;

	if (cmd->args[2])
	{
		ft_putendl_fd("minishell: cd: too many arguments", STDERR_FILENO);
		return (ERROR);
	}
	path = ft_generate_pathcd(cmd, shell);
	if (chdir(path) == -1)
	{
		ft_putendl_fd("minishell: cd: No such file or directory",
			STDERR_FILENO);
		free(path);
		return (ERROR);
	}
	ft_modify_pwd(shell);
	if (path)
		free(path);
	return (SUCCESS);
}
