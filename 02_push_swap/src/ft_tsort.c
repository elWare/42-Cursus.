/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 08:29:03 by jumarque          #+#    #+#             */
/*   Updated: 2025/02/12 09:35:18 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_stack_len(t_stack *stack)
{
	int		len;

	len = 0;
	while (stack)
	{
		len += 1;
		stack = stack->next;
	}
	return (len);
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_len;

	stack_len = ft_stack_len(*stack_a);
	if (stack_len < 2)
		return ;
	else if (stack_len == 2 && !ft_be_sorted(*stack_a))
		sa(stack_a, 1);
	else if (stack_len == 3 && !ft_be_sorted(*stack_a))
		ft_sort_three(stack_a);
	else if (stack_len >= 4)
	{
		ft_get_index(stack_a);
		ft_find_pos_target(stack_a, stack_b);
		if (stack_len == 4 && !ft_be_sorted(*stack_a))
			ft_sort_four(stack_a, stack_b);
		if (stack_len == 5 && !ft_be_sorted(*stack_a))
			ft_sort_five(stack_a, stack_b);
		if (stack_len > 5 && !ft_be_sorted(*stack_a))
			ft_sort_max(stack_a, stack_b);
	}
}

void	ft_sort_three(t_stack **stack)
{
	int	value[3];

	value[0] = (*stack)->value;
	value[1] = (*stack)->next->value;
	value[2] = (*stack)->next->next->value;
	if (value[0] < value[1] && value[1] > value[2] && value[0] < value[2])
	{
		rra(stack, 1);
		sa(stack, 1);
	}
	else if (value[0] > value[1] && value[1] < value[2] && value[0] < value[2])
		sa(stack, 1);
	else if (value[0] < value[1] && value[1] > value[2] && value[0] > value[2])
		rra(stack, 1);
	else if (value[0] > value[1] && value[1] < value[2] && value[0] > value[2])
		ra(stack, 1);
	else if (value[0] > value[1] && value[1] > value[2] && value[0] > value[2])
	{
		ra(stack, 1);
		sa(stack, 1);
	}
}

void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_find_pos_min(*stack_a, ft_find_min(*stack_a)) < 2)
		while (ft_find_min(*stack_a) != (*stack_a)->index)
			ra(stack_a, 1);
	else
		while (ft_find_min(*stack_a) != (*stack_a)->index)
			rra(stack_a, 1);
	pb(stack_a, stack_b, 1);
	if (ft_be_sorted(*stack_a))
		pa(stack_a, stack_b, 1);
	else
	{
		ft_sort_three(stack_a);
		pa(stack_a, stack_b, 1);
	}
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stack_len(*stack_a) > 3)
	{
		if (ft_find_pos_min(*stack_a, ft_find_min(*stack_a)) < 3)
			while (ft_find_min(*stack_a) != (*stack_a)->index)
				ra(stack_a, 1);
		else
			while (ft_find_min(*stack_a) != (*stack_a)->index)
				rra(stack_a, 1);
		pb(stack_a, stack_b, 1);
	}
	if (ft_be_sorted(*stack_a))
	{
		pa(stack_a, stack_b, 1);
		pa(stack_a, stack_b, 1);
	}
	else
	{
		ft_sort_three(stack_a);
		pa(stack_a, stack_b, 1);
		pa(stack_a, stack_b, 1);
	}
}
