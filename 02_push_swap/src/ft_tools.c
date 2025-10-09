/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:07:37 by jumarque          #+#    #+#             */
/*   Updated: 2025/02/12 10:02:43 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(t_stack **s_a, t_stack **s_b, int argc, t_var_ps *va_ps)
{
	ft_end_game(s_a, s_b, argc, va_ps);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit (1);
}

t_stack	*ft_new_stack(int value)
{
	t_stack	*ptr;

	ptr = (t_stack *)malloc(sizeof(t_stack));
	if (ptr == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	ptr->value = value;
	ptr->next = NULL;
	return (ptr);
}

int	ft_abs(int value)
{
	if (value < 0)
		value = -value;
	return (value);
}

int	ft_max_bits(int nbr)
{
	int	max_bits;

	max_bits = 0;
	while ((nbr >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%i, ", stack->value);
		stack = stack->next;
	}
}
