/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:26:24 by jumarque          #+#    #+#             */
/*   Updated: 2025/02/12 09:30:16 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free(t_stack **stack)
{
	t_stack	*ptr_free;

	if (*stack == NULL)
		return ;
	while (*stack)
	{
		ptr_free = (*stack)->next;
		free (*stack);
		*stack = ptr_free;
	}
	*stack = NULL;
	free(ptr_free);
}

void	ft_free_all(t_stack **s_a, t_stack **s_b)
{
	if (s_a != NULL)
		ft_free(s_a);
	if (s_b != NULL)
		ft_free(s_b);
}

void	ft_free_arg(char **str_ptr, int count)
{
	int	index;

	index = 0;
	while (index < count)
	{
		free(str_ptr[index]);
		index++;
	}
	free(str_ptr);
}
