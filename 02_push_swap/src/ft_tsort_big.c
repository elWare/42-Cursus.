/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tsort_big.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 08:44:27 by jumarque          #+#    #+#             */
/*   Updated: 2025/01/30 15:45:11 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	max_bits;
	int	max_num;
	int	bit;
	int	count;

	max_num = ft_find_max(*stack_a);
	max_bits = ft_max_bits(max_num);
	bit = 0;
	while (bit < max_bits)
	{
		count = size;
		while (count--)
		{
			ft_printf("bit: %i, index: %i, ", bit, ((*stack_a)->index));
			if ((((*stack_a)->index >> bit) & 1) == 0)
				pb(stack_a, stack_b, 1);
			else
				ra(stack_a, 1);
		}
		while (*stack_b)
			pa(stack_a, stack_b, 1);
		bit++;
	}
}

void	ft_sort_max(t_stack **stack_a, t_stack **stack_b)
{
	int	max;

	max = ft_stack_len(*stack_a) / 2;
	while (ft_stack_len(*stack_a) > max)
	{
		if ((*stack_a)->index <= max + 1)
			pb(stack_a, stack_b, 1);
		else
			ra(stack_a, 1);
	}
	while (ft_stack_len(*stack_a) >= 1)
		pb(stack_a, stack_b, 1);
	ft_sort_cost(stack_a, stack_b);
}

void	ft_sort_cost(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
	{
		ft_find_pos_target(stack_a, stack_b);
		ft_get_cost(stack_a, stack_b);
		ft_cheap_sort(stack_a, stack_b);
	}
	if (!ft_be_sorted(*stack_a))
		ft_shifte_change(stack_a);
}

void	ft_moves(t_stack **stack_a, t_stack **stack_b, int a_cost, int b_cost)
{
	if (a_cost < 0 && b_cost < 0)
		ft_rrr_rot(stack_a, stack_b, &a_cost, &b_cost);
	else if (a_cost > 0 && b_cost > 0)
		ft_rr_rot(stack_a, stack_b, &a_cost, &b_cost);
	ft_a_rot(stack_a, &a_cost);
	ft_b_rot(stack_b, &b_cost);
	pa(stack_a, stack_b, 1);
}
