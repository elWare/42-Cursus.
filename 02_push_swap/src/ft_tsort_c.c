/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tsort_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:09:22 by jumarque          #+#    #+#             */
/*   Updated: 2025/02/12 10:19:10 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_shifte_change(t_stack **stack_a)
{
	int	low_pos;
	int	len;

	len = ft_stack_len(*stack_a);
	low_pos = ft_low_index(stack_a);
	if (low_pos > len / 2)
	{
		while (low_pos < len)
		{
			rra(stack_a, 1);
			low_pos++;
		}
	}
	else
	{
		while (low_pos > 0)
		{
			ra(stack_a, 1);
			low_pos--;
		}
	}
}

int	ft_low_index(t_stack **stack)
{
	t_stack	*tmp;
	int		low_index;
	int		low_pos;

	tmp = *stack;
	low_index = INT_MAX;
	ft_pos(stack);
	low_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < low_index)
		{
			low_index = tmp->index;
			low_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (low_pos);
}

int	ft_be_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_be_nbr(char *str)
{
	long	nbr;
	int		neg;

	neg = 1;
	nbr = 0;
	if (*str == '-' || *str == '+')
	{
		neg = -1;
		str++;
	}
	if (!*str)
		return (-1);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (-2);
		nbr = (nbr * 10) + *str - '0';
		str++;
	}
	nbr = neg * nbr;
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (-3);
	return (1);
}

void	ft_be_duplicated(t_stack **s_a, t_stack **s_b, int argc, t_var_ps *v)
{
	t_stack	*ptr_cmp;
	t_stack	*stack;

	stack = *s_a;
	if (stack == NULL)
		ft_error(s_a, s_b, argc, v);
	while (stack->next)
	{
		ptr_cmp = stack->next;
		while (ptr_cmp)
		{
			if (stack->value == ptr_cmp->value)
				ft_error(s_a, s_b, argc, v);
			ptr_cmp = ptr_cmp->next;
		}
		stack = stack->next;
	}
}
