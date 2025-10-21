/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_exec_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:35:42 by emcorona          #+#    #+#             */
/*   Updated: 2025/08/25 12:34:20 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	remove_backslashes(char *str);

int	exec_echo(t_cmd *cmd)
{
	int	fd;

	if (!cmd || !cmd->args)
		return (ERROR);
	if (cmd->exit_status == 1)
		return (ERROR);
	fd = dup(STDOUT_FILENO);
	if (fd == -1)
		return (ERROR);
	if (cmd->outfile && stdout_to_outfile(cmd->outfile, cmd->append) != 0)
		return (ERROR);
	ft_print_echo(cmd->args);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (SUCCESS);
}

int	stdout_to_outfile(char *outfile, int append)
{
	int	fd;

	if (append == 1)
		fd = open(outfile, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("minishell: echo:");
		return (1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("minishell: echo:");
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

void	ft_print_echo(char **args)
{
	int	i;
	int	flag_option;

	i = 1;
	flag_option = 0;
	if (!args[1])
	{
		printf("\n");
		return ;
	}
	while (args[i] && check_option_echo(args[i]) != 0)
	{
		flag_option = 1;
		i++;
	}
	while (args[i])
	{
		remove_backslashes(args[i]);
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (flag_option == 0)
		printf("\n");
}

int	check_option_echo(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-')
		return (0);
	i++;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (i > 1);
}

static void	remove_backslashes(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '\\')
			str[j++] = str[i];
		else
			i++;
		i++;
	}
	str[j] = '\0';
}
