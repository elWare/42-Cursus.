/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:49:12 by jumarque          #+#    #+#             */
/*   Updated: 2025/02/12 09:57:48 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include "printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_stack
{
	int				index;
	int				value;
	int				pos;
	int				target;
	int				a_cost;
	int				b_cost;
	int				cost;
	struct s_stack	*next;
}	t_stack;

typedef struct s_var_ps
{
	char	**ptr_args;
	int		args;
	int		i;
	int		exit;
}	t_var_ps;

///////////////////// File ft_push.c //////////////////////////////
void	pa(t_stack **stack_a, t_stack	**stack_b, int print);
void	pb(t_stack **stack_a, t_stack	**stack_b, int print);
///////////////////// ft_rotate_down.c ////////////////////////////
void	rra(t_stack **stack, int print);
void	rrb(t_stack **stack, int print);
void	rrr(t_stack **stack_a, t_stack **stack_b, int print);
void	ft_rrr_rot(t_stack **stack_a, t_stack **s_b, int *a_cost, int *b_cost);
void	ft_b_rot(t_stack **stack, int *cost);
//////////////////// ft_rotate_up.c ////////////////////////////////
void	ra(t_stack **stack, int print);
void	rb(t_stack **stack, int print);
void	rr(t_stack **stack_a, t_stack **stack_b, int print);
void	ft_a_rot(t_stack **stack, int *cost);
void	ft_rr_rot(t_stack **s_a, t_stack **s_b, int *cost_a, int *cost_b);
///////////////////// ft_swap.c  ////////////////////////////////////
void	sa(t_stack **stack, int print);
void	sb(t_stack **stack, int print);
void	ss(t_stack **stack_a, t_stack **stack_b, int print);
///////////////////// ft_tfind_index.c /////////////////////////////
void	ft_get_cost(t_stack **stack_a, t_stack **stack_b);
void	ft_cheap_sort(t_stack **stack_a, t_stack **stack_b);
char	**ft_to_args(char **argv, int *argc);
void	ft_end_game(t_stack **s_a, t_stack **s_b, int argc, t_var_ps *v);
////////////////////   ft_tfind.c //////////////////////////////
int		ft_find_min(t_stack *stack);
int		ft_find_pos_min(t_stack	*stack, int i_min);
int		ft_find_max(t_stack *stack);
int		ft_find_pos_max(t_stack	*stack, int i_max);
//////////////////// ft_free.c /////////////////////////////////
void	ft_free(t_stack **stack);
void	ft_free_all(t_stack **stack_a, t_stack **stack_b);
void	ft_free_arg(char **str_ptr, int count);
////////////////////  ft_tindex.c //////////////////////////////
void	ft_get_index(t_stack **stack);
t_stack	*ft_cpy_stack(t_stack **stack);
void	ft_sort_list(t_stack **stack);
int		ft_find_index(t_stack *sorted_list, int value);
////////////////////  ft_tools.c  //////////////////////////////
void	ft_error(t_stack **s_a, t_stack **s_b, int argc, t_var_ps *va_ps);
t_stack	*ft_new_stack(int value);
int		ft_abs(int value);
int		ft_max_bits(int nbr);
void	ft_print_stack(t_stack *stack);
////////////////////  ft_tpos.c   ///////////////////////////////
void	ft_find_pos_target(t_stack **stack_a, t_stack **stack_b);
int		ft_target(t_stack *stack, int i_min, int target, int pos_in_s);
void	ft_pos(t_stack **stack);
void	ft_init_ptr(t_stack **s_a, t_stack **s_b, t_stack **p_tmp);
////////////////////   ft_tsort_big.c  ///////////////////////////
void	ft_sort_max(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_cost(t_stack **stack_a, t_stack **stack_b);
void	ft_moves(t_stack **stack_a, t_stack **stack_b, int a_cost, int b_cost);
void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b, int size);
////////////////////  ft_tsort_c.c   ///////////////////////////////
void	ft_shifte_change(t_stack **stack_a);
int		ft_low_index(t_stack **stack);
void	ft_be_duplicated(t_stack **s_a, t_stack **s_b, int argc, t_var_ps *v);
int		ft_be_nbr(char *str);
int		ft_be_sorted(t_stack *stack);
////////////////////  ft_tsort.c   //////////////////////////////////
void	ft_sort(t_stack **stack_a, t_stack **stack_b);
int		ft_stack_len(t_stack *stack);
void	ft_sort_three(t_stack **stack);
void	ft_sort_four(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_five(t_stack **stack_a, t_stack **stack_b);

#endif
