/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 08:21:47 by jumarque          #+#    #+#             */
/*   Updated: 2025/02/06 10:08:58 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	ft_print_screen(int pid)
{
	system("clear");
	ft_printf("* * *  WELLCOME TO MINITALK SERVER  * * *\n");
	ft_printf("* * * * * * * * * * * * * * * * * * * * *\n");
	ft_printf("\n>>>         PID number: %d       <<<\n", pid);
	ft_printf("\n>>> waiting for messages, please wait <<<\n");
	ft_printf("\n>>>   ... or press ctrl + c to exit   <<<\n\n");
}

void	ft_btoa(int sig)
{
	static int	bit;
	static int	i;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_print_screen(pid);
		signal(SIGUSR1, ft_btoa);
		signal(SIGUSR2, ft_btoa);
		while (1)
		{
			pause();
		}
	}
	else
	{
		ft_printf("Error: server without argument");
		return (1);
	}
	return (0);
}
