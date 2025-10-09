/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:55:13 by jumarque          #+#    #+#             */
/*   Updated: 2025/01/29 09:22:02 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack **stack, int print)
{
	t_stack	*ptr_first;
	t_stack	*ptr_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	ptr_first = *stack;
	ptr_last = ptr_first->next;
	while (ptr_last->next)
		ptr_last = ptr_last->next;
	ptr_last->next = ptr_first;
	*stack = ptr_first->next;
	ptr_first->next = NULL;
	if (print)
		ft_printf("ra\n");
}

void	rb(t_stack **stack, int print)
{
	t_stack	*ptr_first;
	t_stack	*ptr_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	ptr_first = *stack;
	ptr_last = ptr_first->next;
	while (ptr_last->next)
		ptr_last = ptr_last->next;
	ptr_last->next = ptr_first;
	*stack = ptr_first->next;
	ptr_first->next = NULL;
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b, int print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print == 1)
		ft_printf("rr\n");
}

void	ft_a_rot(t_stack **stack, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			(*cost)--;
			ra(stack, 1);
		}
		else if (*cost < 0)
		{
			(*cost)++;
			rra(stack, 1);
		}
	}
}

void	ft_rr_rot(t_stack **s_a, t_stack **s_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(s_a, s_b, 1);
	}
}
