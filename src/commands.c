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

void swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **a)
{
	swap(a);
	write (1, "sa\n", 3);
}

// void	sb(t_stack **b)
// {
// 	swap(b);
// 	write (1, "sb\n", 3);
// }

// void	ss(t_stack **a, t_stack **b)
// {
// 	swap(a);
// 	swap(b);
// 	write (1, "ss\n", 3);
// }

void	rotate(t_stack **stack)
{
	t_stack *last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = find_last(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	write (1, "ra\n", 3);
}

// void	rb(t_stack **b)
// {
// 	rotate(b);
// 	write (1, "rb\n", 3);
// }

// void	rr(t_stack **a, t_stack **b)
// {
// 	rotate(a);
// 	rotate(b);
// 	write (1, "rr\n", 3);
// }

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

// void	rrb(t_stack **b)
// {
// 	rev_rotate(b);
// 	write (1, "rrb\n", 4);
// }

// void	rrr(t_stack **a, t_stack **b)
// {
// 	rev_rotate(a);
// 	rev_rotate(b);
// 	write (1, "rrr\n", 4);
// }

// void	push(t_stack **dst, t_stack **src)
// {
// 	t_stack	*push_node;
// 	t_stack	*dst_tmp;

// 	push_node = *src;
// 	*src = (*src)->next;
// 	if (*dst == NULL)
// 	{
// 		*dst = push_node;
// 		push_node->next = NULL;
// 	}
// 	else
// 	{
// 		push_node->next = *dst;
// 		*dst = push_node;
// 	}
// }

// void	pa(t_stack **a, t_stack **b)
// {
// 	push(a, b); 
// 	write (1, "pa\n", 3);
// }

// void	pb(t_stack **b, t_stack **a)
// {
// 	push(b, a);
// 	write (1, "pb\n", 3);
// }