/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 08:15:10 by jumarque          #+#    #+#             */
/*   Updated: 2025/02/06 10:11:35 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>
# include <stdio.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

void	ft_btoa(int sig, siginfo_t *info, void *context);
void	ft_atob(int pid, char c);
void	ft_print_screen(int pid);
void	confirm_msg(int signal);
void	ft_connected(int pid_server, char *pid_client);

#endif