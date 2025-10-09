/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:12:17 by jumarque          #+#    #+#             */
/*   Updated: 2025/02/07 10:20:48 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack **stack, int print)
{
	t_stack	*ptr_tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	ptr_tmp = (*stack);
	(*stack) = ptr_tmp->next;
	ptr_tmp->next = (*stack)->next;
	(*stack)->next = ptr_tmp;
	if (print == 1)
		ft_printf("sa\n");
}

void	sb(t_stack **stack, int print)
{
	t_stack	*ptr_tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	ptr_tmp = (*stack);
	(*stack) = ptr_tmp->next;
	ptr_tmp->next = (*stack)->next;
	(*stack)->next = ptr_tmp;
	if (print == 1)
		ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (print)
		ft_printf("ss\n");
}
