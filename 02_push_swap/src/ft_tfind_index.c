/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tfind_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 08:21:14 by jumarque          #+#    #+#             */
/*   Updated: 2025/02/12 10:36:20 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		len_a;
	int		len_b;

	tmp_b = *stack_b;
	len_a = ft_stack_len(*stack_a);
	len_b = ft_stack_len(*stack_b);
	while (tmp_b)
	{
		tmp_b->b_cost = tmp_b->pos;
		if (tmp_b->pos > len_b / 2)
			tmp_b->b_cost = (len_b - tmp_b->pos) * -1;
		tmp_b->a_cost = tmp_b->target;
		if (tmp_b->target > len_a / 2)
			tmp_b->a_cost = (len_a - tmp_b->target) * -1;
		tmp_b = tmp_b->next;
	}
}

void	ft_cheap_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		a_cost;
	int		b_cost;
	int		cheap;
	int		current_cost;

	tmp_b = *stack_b;
	cheap = INT_MAX;
	while (tmp_b)
	{
		current_cost = ft_abs(tmp_b->a_cost) + ft_abs(tmp_b->b_cost);
		if (current_cost < cheap)
		{
			cheap = current_cost;
			a_cost = tmp_b->a_cost;
			b_cost = tmp_b->b_cost;
		}
		tmp_b = tmp_b->next;
	}
	ft_moves(stack_a, stack_b, a_cost, b_cost);
}

char	**ft_to_args(char **argv, int *argc)
{
	char	**ptr_args;
	int		i;

	ptr_args = NULL;
	i = 0;
	if (*argc == 2)
	{
		ptr_args = ft_split(argv[1], ' ');
		while (ptr_args[i])
			i++;
		*argc = i;
	}
	else
	{
		*argc -= 1;
		ptr_args = ++argv;
	}
	*argc -= 1;
	return (ptr_args);
}

void	ft_end_game(t_stack **s_a, t_stack **s_b, int argc, t_var_ps *v)
{
	ft_free_all(s_a, s_b);
	if (argc == 2 && v->i <= 1)
		ft_free_arg(v->ptr_args, v->i);
	else if (argc == 2 && v->i > 1)
		ft_free_arg(v->ptr_args, v->i + 1);
}
