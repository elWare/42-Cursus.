/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:54:33 by jumarque          #+#    #+#             */
/*   Updated: 2025/02/12 10:16:57 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*ptr_tmp;
	t_var_ps	pa_var;

	if (argc < 2)
		return (1);
	ft_init_ptr(&stack_a, &stack_b, &ptr_tmp);
	pa_var.args = argc;
	pa_var.ptr_args = ft_to_args(argv, &pa_var.args);
	pa_var.i = pa_var.args;
	while (pa_var.args >= 0)
	{
		if (0 > ft_be_nbr(pa_var.ptr_args[pa_var.args]))
			ft_error(&stack_a, &stack_b, argc, &pa_var);
		ptr_tmp = ft_new_stack(ft_atoi(pa_var.ptr_args[pa_var.args--]));
		ptr_tmp->next = stack_a;
		stack_a = ptr_tmp;
	}
	ft_be_duplicated(&stack_a, &stack_b, argc, &pa_var);
	if (!ft_be_sorted(stack_a))
		ft_sort(&stack_a, &stack_b);
	ft_end_game(&stack_a, &stack_b, argc, &pa_var);
	return (0);
}
