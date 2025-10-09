/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 08:39:11 by jumarque          #+#    #+#             */
/*   Updated: 2025/02/07 09:52:58 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk_bonus.h"

void	ft_connected(int pid_server, char *pid_client)
{
	int	i;

	i = 0;
	while (pid_client[i] != '\0')
	{
		ft_atob(pid_server, pid_client[i]);
		i++;
	}
	ft_atob(pid_server, '\n');
	ft_atob(pid_server, '\0');
}

void	ft_atob(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
		bit++;
	}
}

void	confirm_msg(int signal)
{
	if (signal == SIGUSR2)
	{
		ft_printf(">>> Message sent and recived ok <<<\n");
		exit(0);
	}
	else if (signal == SIGUSR1)
		ft_printf(">>> ERROR <<<\n");
}

int	main(int argc, char **argv)
{
	int	pid_server;

	if (argc == 3)
	{
		pid_server = ft_atoi(argv[1]);
		signal(SIGUSR2, confirm_msg);
		ft_connected(pid_server, argv[2]);
		ft_printf("Waiting server request ......\n");
		pause();
	}
	else
	{
		ft_printf("Error: minitalk <pid> <str>");
		return (1);
	}
	return (0);
}
