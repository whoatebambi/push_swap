/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:33:43 by fcouserg          #+#    #+#             */
/*   Updated: 2024/01/01 17:57:46 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
# include "../libft/inc/libft.h"

typedef struct s_stack
{
	int				nbr;
	int				push_cost;
	int				index;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

// parsing.c
void	single_argv_to_array(char ***argv);
void	append_stack(t_stack **a, char **argv);
t_stack	*parse_stack(int argc, char **argv);

// parsing_error_handling.c
void	check_digit(char **argv);
void	check_int(char **argv);
void	check_duplicate(char **argv);
void	error_and_exit(char *str);
void	free_stack(t_stack **stack, int std_value);

// lst_utils.c
int		stack_len(t_stack *stack);
t_stack	*find_last(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_before_last(t_stack *stack);

// sorting.c
int		check_sorting(t_stack *a);
void	sort_three(t_stack **a);
void	sort_stacks(t_stack **a, t_stack **b);

// sorting_push.c
void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
t_stack	*get_cheapest(t_stack *a);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void	min_on_top(t_stack **a);

// sorting_init_a.c
void	init_stack_a(t_stack *a, t_stack *b);
void	current_index(t_stack *stack);
void	set_target_a(t_stack *a, t_stack *b);
void	cost_analysis_a(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *a);

// sorting_init_b.c
void	init_stack_b(t_stack *a, t_stack *b);
void	set_target_b(t_stack *a, t_stack *b);

// commands_push.c
void	push(t_stack **dst, t_stack **src);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

// commands_rev_rotate.c
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rev_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// commands_rotate.c
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

// commands_swap.c
void 	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

#endif