/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:32:46 by jumarque          #+#    #+#             */
/*   Updated: 2025/01/29 09:22:22 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_find_min(t_stack *stack)
{
	int	min;

	min = stack->index;
	stack = stack->next;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

int	ft_find_pos_min(t_stack	*stack, int i_min)
{
	int	pos_min;

	pos_min = 0;
	while (stack)
	{
		if (stack->index == i_min)
			return (pos_min);
		stack = stack->next;
		pos_min++;
	}
	return (pos_min);
}

int	ft_find_max(t_stack *stack)
{
	int	max;

	max = stack->index;
	stack = stack->next;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	ft_find_pos_max(t_stack	*stack, int i_max)
{
	int	pos_max;

	pos_max = 0;
	while (stack)
	{
		if (stack->index == i_max)
			return (pos_max);
		stack = stack->next;
		pos_max++;
	}
	return (pos_max);
}
