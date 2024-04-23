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

// # define INT_MIN -2147483648
// # define INT_MAX 2147483647

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
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
void	check_digit(char **argv);
void	check_int(char **argv);
void	check_duplicate(char **argv);
void	append_stack(t_stack **a, char **argv);
t_stack	*parse_stack(int argc, char **argv);
void	error_and_exit(char *str);

// lst_utils.c
t_stack	*find_last(t_stack *stack);
void	free_stack(t_stack **stack, int std_value);
int		stack_len(t_stack *stack);
void	print_stack(t_stack *a);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_before_last(t_stack *stack);
void	min_on_top(t_stack **a);

// sorting.c
int		check_sorting(t_stack *a);
void	sort_three(t_stack **a);
void	sort_stacks(t_stack **a, t_stack **b);
void	init_stack_a(t_stack *a, t_stack *b);
void	current_index(t_stack *stack);
void	set_target_a(t_stack *a, t_stack *b);
void	cost_analysis_a(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *a);
void	move_a_to_b(t_stack **a, t_stack **b);
t_stack	*get_cheapest(t_stack *a);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void	init_stack_b(t_stack *a, t_stack *b);
void	set_target_b(t_stack *a, t_stack *b);
void	move_b_to_a(t_stack **a, t_stack **b);


// commands.c
void 	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rev_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	push(t_stack **dst, t_stack **src);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);


#endif