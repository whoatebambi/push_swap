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

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct s_stack
{
	int				nbr;
	int				push_cost;
	int				index;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
}	t_stack;

// parsing
char		**ft_split(char const *s, char c);
int			error_syntax(char *str);
int			error_duplicate(char **array, int nb, int i);
int			ft_atoi(char *str);
void		ft_error(void);
char		*ft_itoa(int n);
int			s_intlen(unsigned int nbr);
int			s_isneg(int n);
int			ft_strcmp(const char *s1, const char *s2);
void		free_array(char **array);

// push_swap
void	init_nodes_a(t_stack *a, t_stack *b);
void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	current_index(t_stack *stack);
void	min_on_top(t_stack **a);
void	set_target_a(t_stack *a, t_stack *b);
void	cost_analysis_a(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *stack);
void	init_nodes_b(t_stack *a, t_stack *b);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void	set_target_b(t_stack *a, t_stack *b);
void	ft_sort(t_stack **a);
t_stack	*ft_process(int argc, char **argv);
int		stack_sorted(t_stack *a);

// commands
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

// stack_utils
int		stack_len(t_stack *stack);
t_stack	*find_last(t_stack *stack);
t_stack	*find_before_last(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
void	append_node(t_stack **a, int n);
void	free_stack(t_stack **stack);
void	append_stack(t_stack **a, char **array);


#endif