/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 08:39:11 by jumarque          #+#    #+#             */
/*   Updated: 2025/02/06 10:06:40 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

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
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid_server;

	if (argc == 3)
	{
		pid_server = ft_atoi(argv[1]);
		ft_connected(pid_server, argv[2]);
	}
	else
	{
		ft_printf("Error: minitalk <pid> <str>");
		return (1);
	}
	return (0);
}
