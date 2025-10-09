/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 08:21:47 by jumarque          #+#    #+#             */
/*   Updated: 2025/02/06 10:10:32 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk_bonus.h"

void	ft_print_screen(int pid)
{
	system("clear");
	ft_printf("* * *  WELLCOME TO MINITALK SERVER  * * *\n");
	ft_printf("* * * * * * * * * * * * * * * * * * * * *\n");
	ft_printf("\n>>>         PID number: %d       <<<\n", pid);
	ft_printf("\n>>> waiting for messages, please wait <<<\n");
	ft_printf("\n>>>   ... or press ctrl + c to exit   <<<\n\n");
}

void	ft_btoa(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;

	(void)context;
	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (i == '\0')
		{
			ft_printf("\n>>> messege recived ok <<<\n");
			kill(info->si_pid, SIGUSR2);
		}
		else
			ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	memset(&sa, 0, sizeof(sa));
	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_print_screen(pid);
		sa.sa_sigaction = ft_btoa;
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
			pause();
	}
	else
	{
		ft_printf("Error: server without argument");
		return (1);
	}
	return (0);
}
