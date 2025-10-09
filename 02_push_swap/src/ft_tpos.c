/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tpos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:27:03 by jumarque          #+#    #+#             */
/*   Updated: 2025/01/29 09:22:47 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_find_pos_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*ptr_b;
	int		pos_in_a;

	ft_pos(stack_a);
	ft_pos(stack_b);
	ptr_b = *stack_b;
	pos_in_a = 0;
	while (ptr_b)
	{
		pos_in_a = ft_target(*stack_a, ptr_b->index, INT_MAX, pos_in_a);
		ptr_b->target = pos_in_a;
		ptr_b = ptr_b->next;
	}
}

int	ft_target(t_stack *stack, int i_min, int target, int pos_in_s)
{
	t_stack	*ptr_s;

	ptr_s = stack;
	while (ptr_s)
	{
		if (ptr_s->index > i_min && ptr_s->index < target)
		{
			pos_in_s = ptr_s->pos;
			target = ptr_s->index;
		}
		ptr_s = ptr_s->next;
	}
	if (target != INT_MAX)
		return (pos_in_s);
	ptr_s = stack;
	while (ptr_s)
	{
		if (ptr_s->index < target)
		{
			pos_in_s = ptr_s->pos;
			target = ptr_s->index;
		}
		ptr_s = ptr_s->next;
	}
	return (pos_in_s);
}

void	ft_pos(t_stack **stack)
{
	t_stack	*ptr_stack;
	int		pos;

	ptr_stack = *stack;
	pos = 0;
	while (ptr_stack)
	{
		ptr_stack->pos = pos;
		pos++;
		ptr_stack = ptr_stack->next;
	}
}

void	ft_init_ptr(t_stack **s_a, t_stack **s_b, t_stack **p_t)
{
	*s_a = NULL;
	*s_b = NULL;
	*p_t = NULL;
}
