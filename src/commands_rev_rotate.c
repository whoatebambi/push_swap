/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:33:43 by fcouserg          #+#    #+#             */
/*   Updated: 2023/11/10 18:34:28 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node && and the current `a` node is not the cheapest
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate(t_stack **stack)
{
	t_stack *last;
	t_stack *last_before;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = find_last(*stack);
	last_before = find_before_last(*stack);
	last_before->next = NULL;
	last->next = *stack;
	*stack = last; 
}

void	rra(t_stack **a)
{
	rev_rotate(a);
	write (1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	rev_rotate(b);
	write (1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write (1, "rrr\n", 4);
}
