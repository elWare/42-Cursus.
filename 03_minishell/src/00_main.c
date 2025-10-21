/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:32:54 by juagomez          #+#    #+#             */
/*   Updated: 2025/08/27 12:10:05 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main(int argc, char **argv, char **environment)
{
	t_shell	*shell;

	(void)argc;
	(void)argv;
	if (validate_environment(environment) == FAILURE)
		return (FAILURE);
	shell = initialize_shell();
	if (load_environment_variables(shell, environment) == FAILURE)
	{
		cleanup_minishell(shell);
		ft_putendl_fd(ERROR_ENVIRONMENT, STDERR_FILENO);
		return (FAILURE);
	}
	ft_shellevel(shell);
	if (execute_shell(shell) == FAILURE)
	{
		cleanup_minishell(shell);
		return (FAILURE);
	}
	cleanup_minishell(shell);
	return (SUCCESS);
}

int	validate_environment(char **environment)
{
	if (!environment | !*environment)
	{
		ft_putendl_fd(ERROR_ENVIRONMENT, STDERR_FILENO);
		return (FAILURE);
	}
	return (SUCCESS);
}

t_shell	*initialize_shell(void)
{
	t_shell	*shell;

	shell = (t_shell *) malloc(sizeof(t_shell));
	if (!shell)
	{
		ft_putendl_fd(ERR_MEM_ALLOC, STDERR_FILENO);
		return (NULL);
	}
	shell->input = NULL;
	shell->environment = NULL;
	shell->readonly_vars = NULL;
	shell->exit_status = SUCCESS;
	shell->last_exit_status = SUCCESS;
	shell->commands_list = NULL;
	return (shell);
}

int	load_environment_variables(t_shell *shell, char **environment)
{
	int	env_count;
	int	index;

	if (!shell || !environment)
		return (ft_putendl_fd(ERR_MEM_ALLOC, STDERR_FILENO), FAILURE);
	env_count = 0;
	index = 0;
	while (environment[env_count])
		env_count++;
	shell->environment = (char **) malloc(sizeof(char *) * (env_count + 1));
	if (env_count <= 0 || !shell->environment)
		return (ft_putendl_fd(ERROR_ENVIRONMENT, STDERR_FILENO), FAILURE);
	while (environment[index])
	{
		shell->environment[index] = ft_strdup(environment[index]);
		if (!shell->environment[index])
			return (ft_putendl_fd(ERROR_ENVIRONMENT, STDERR_FILENO), FAILURE);
		index++;
	}
	shell->environment[index] = NULL;
	return (SUCCESS);
}

void	cleanup_minishell(t_shell *shell)
{
	if (!shell)
		return ;
	free_matrix(shell->environment);
	free_iteration_input(shell);
	free(shell);
	shell = NULL;
}
