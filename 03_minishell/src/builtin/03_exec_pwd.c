/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_exec_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:52:44 by emcorona          #+#    #+#             */
/*   Updated: 2025/08/11 11:45:05 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	exec_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		perror("minishell: pwd:");
		return (ERROR);
	}
	printf("%s\n", pwd);
	free(pwd);
	return (SUCCESS);
}
