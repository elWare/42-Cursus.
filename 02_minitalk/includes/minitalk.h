/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 08:15:10 by jumarque          #+#    #+#             */
/*   Updated: 2025/02/05 08:53:40 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>
# include <stdio.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

void	ft_btoa(int signal);
void	ft_atob(int pid, char c);
void	ft_print_screen(int pid);

#endif