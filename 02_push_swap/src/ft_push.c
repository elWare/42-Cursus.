/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:51:10 by jumarque          #+#    #+#             */
/*   Updated: 2025/01/29 09:21:13 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_stack **stack_a, t_stack	**stack_b, int print)
{
	t_stack	*ptr_tmp;

	if (*stack_b == NULL)
		return ;
	ptr_tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_a == NULL)
	{
		*stack_a = ptr_tmp;
		(*stack_a)->next = NULL;
	}
	else
	{
		ptr_tmp->next = *stack_a;
		*stack_a = ptr_tmp;
	}
	if (print == 1)
		ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack	**stack_b, int print)
{
	t_stack	*ptr_tmp;

	if (*stack_a == NULL)
		return ;
	ptr_tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_b == NULL)
	{
		*stack_b = ptr_tmp;
		(*stack_b)->next = NULL;
	}
	else
	{
		ptr_tmp->next = *stack_b;
		*stack_b = ptr_tmp;
	}
	if (print == 1)
		ft_printf("pb\n");
}
