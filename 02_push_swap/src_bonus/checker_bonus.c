/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 09:20:03 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/09 09:20:06 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../include/get_next_line/get_next_line.h"
#include "../include/push_swap.h"

int	ft_operations(t_stack **stack_a, t_stack **stack_b, char *operation)
{
	if (!ft_strncmp(operation, "sa\n", 3))
		sa(stack_a, 0);
	else if (!ft_strncmp(operation, "sb\n", 3))
		sb(stack_b, 0);
	else if (!ft_strncmp(operation, "ss\n", 3))
		ss(stack_a, stack_b, 0);
	else if (!ft_strncmp(operation, "pa\n", 3))
		pa(stack_a, stack_b, 0);
	else if (!ft_strncmp(operation, "pb\n", 3))
		pb(stack_a, stack_b, 0);
	else if (!ft_strncmp(operation, "ra\n", 3))
		ra(stack_a, 0);
	else if (!ft_strncmp(operation, "rb\n", 3))
		rb(stack_b, 0);
	else if (!ft_strncmp(operation, "rr\n", 3))
		rr(stack_a, stack_b, 0);
	else if (!ft_strncmp(operation, "rra\n", 4))
		rra(stack_a, 0);
	else if (!ft_strncmp(operation, "rrb\n", 4))
		rrb(stack_b, 0);
	else if (!ft_strncmp(operation, "rrr\n", 4))
		rrr(stack_a, stack_b, 0);
	else
		ft_printf("Error\n");
	return (1);
}

void	ft_include(t_stack **s_a, t_stack **s_b, int argc, t_var_ps *pa_var)
{
	t_stack		*ptr_tmp;

	while (pa_var->args >= 0)
	{
		if (0 > ft_be_nbr(pa_var->ptr_args[pa_var->args]))
			ft_error(s_a, s_b, argc, pa_var);
		ptr_tmp = ft_new_stack(ft_atoi(pa_var->ptr_args[pa_var->args--]));
		ptr_tmp->next = *s_a;
		*s_a = ptr_tmp;
	}
	ft_be_duplicated(s_a, s_b, argc, pa_var);
	if (ft_be_sorted(*s_a))
		return ;
}

int	main(int argc, char **argv)
{
	char		*operation;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_var_ps	pa_var;

	ft_init_ptr(&stack_a, &stack_b, &stack_a);
	pa_var.args = argc;
	pa_var.ptr_args = ft_to_args(argv, &pa_var.args);
	pa_var.i = pa_var.args;
	ft_include(&stack_a, &stack_b, argc, &pa_var);
	while (1)
	{
		operation = get_next_line(STDIN_FILENO);
		if (!operation)
			break ;
		if (ft_operations(&stack_a, &stack_b, operation) == 0)
			ft_end_game(&stack_a, &stack_b, argc, &pa_var);
		free(operation);
	}
	if ((stack_a) && (stack_b == NULL) && (ft_be_sorted(stack_a)))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_end_game(&stack_a, &stack_b, argc, &pa_var);
	return (0);
}
