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

# define INT_MIN -2147483648
# define INT_MAX 2147483647

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
	struct s_stack	*target_node;
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
t_stack	*find_before_last(t_stack *stack);

// sorting.c
int		check_sorting(t_stack *a);
void	sort_three(t_stack **a);

// commands.c
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	rev_rotate(t_stack **stack);
void	sa(t_stack **a);
void	ra(t_stack **a);
void	rra(t_stack **a);


#endif