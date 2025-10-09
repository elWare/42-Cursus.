/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tindex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 09:40:28 by jumarque          #+#    #+#             */
/*   Updated: 2025/02/12 10:08:17 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_get_index(t_stack **stack)
{
	t_stack	*stack_org;
	t_stack	*stack_cpy;
	t_stack	*ereser;

	stack_cpy = ft_cpy_stack (stack);
	ft_sort_list(&stack_cpy);
	stack_org = (*stack);
	while (stack_org)
	{
		stack_org->index = ft_find_index(stack_cpy, stack_org->value);
		stack_org = stack_org->next;
	}
	while (stack_cpy)
	{
		ereser = stack_cpy;
		stack_cpy = stack_cpy->next;
		free(ereser);
	}
}

t_stack	*ft_cpy_stack(t_stack **s_a)
{
	t_stack	*stack_cpy;
	t_stack	*stack_node;
	t_stack	*stack;

	stack_cpy = NULL;
	stack = *s_a;
	while (stack)
	{
		stack_node = (t_stack *)malloc(sizeof(t_stack));
		if (stack_node == NULL)
		{
			ft_free_all(&stack, s_a);
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit (1);
		}
		stack_node->next = stack_cpy;
		stack_cpy = stack_node;
		stack_node->value = stack->value;
		stack = stack->next;
	}
	return (stack_cpy);
}

void	ft_sort_list(t_stack **stack)
{
	t_stack	*list_old;
	t_stack	*tmp_node;
	int		tmp_value;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	list_old = *stack;
	while (list_old && list_old->next)
	{
		tmp_node = list_old->next;
		while (tmp_node)
		{
			if (list_old->value > tmp_node->value)
			{
				tmp_value = list_old->value;
				list_old->value = tmp_node->value;
				tmp_node->value = tmp_value;
			}
			tmp_node = tmp_node->next;
		}
		list_old = list_old->next;
	}
}

int	ft_find_index(t_stack *sorted_list, int value)
{
	int	index;

	index = 1;
	while (sorted_list)
	{
		if (sorted_list->value == value)
			return (index);
		index++;
		sorted_list = sorted_list->next;
	}
	return (-1);
}
