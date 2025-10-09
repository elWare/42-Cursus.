/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:12:49 by jumarque          #+#    #+#             */
/*   Updated: 2025/02/11 10:42:10 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "./push_swap.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"

void	ft_include(t_stack **s_a, t_stack **s_b, int argc, t_var_ps *pa_var);
int		ft_operations(t_stack **stack_a, t_stack **stack_b, char *operation);
t_stack	*ft_checker_stacknew(int value);

#endif
