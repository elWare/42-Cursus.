/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:04:03 by jumarque          #+#    #+#             */
/*   Updated: 2025/01/29 09:21:55 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_stack **stack, int print)
{
	t_stack	*ptr_pre;
	t_stack	*ptr_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	ptr_pre = *stack;
	ptr_last = ptr_pre->next;
	while (ptr_last->next)
	{
		ptr_pre = ptr_last;
		ptr_last = ptr_last->next;
	}
	ptr_last->next = *stack;
	*stack = ptr_last;
	ptr_pre->next = NULL;
	if (print == 1)
		ft_printf("rra\n");
}

void	rrb(t_stack **stack, int print)
{
	t_stack	*ptr_pre;
	t_stack	*ptr_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	ptr_pre = *stack;
	ptr_last = ptr_pre->next;
	while (ptr_last->next)
	{
		ptr_pre = ptr_last;
		ptr_last = ptr_last->next;
	}
	ptr_last->next = *stack;
	*stack = ptr_last;
	ptr_pre->next = NULL;
	if (print == 1)
		ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print == 1)
		ft_printf("rrr\n");
}

void	ft_rrr_rot(t_stack **s_a, t_stack **s_b, int *a_cost, int *b_cost)
{
	while (*a_cost < 0 && *b_cost < 0)
	{
		(*a_cost)++;
		(*b_cost)++;
		rrr(s_a, s_b, 1);
	}
}

void	ft_b_rot(t_stack **stack, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			(*cost)--;
			rb(stack, 1);
		}
		else if (*cost < 0)
		{
			(*cost)++;
			rrb(stack, 1);
		}
	}
}
