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

void	move_a_to_b(t_stack **a, t_stack **b) ////////////////////////////
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median == true 
		&& cheapest_node->target->above_median == true)
		rotate_both(a, b ,cheapest_node);
	if (cheapest_node->above_median == false 
		&& cheapest_node->target->above_median == false)
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a'); //Ensure the cheapest nodes is at the top, ready for pushing
	prep_for_push(b, cheapest_node->target, 'b'); //Ensure the target node is at the top, ready for pushing
	pb(b, a);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target, 'a'); //Ensure the target node is at the top, ready for pushing
	pa(a, b);
}

t_stack	*get_cheapest(t_stack *a)
{
	while (a != NULL)
	{
		if (a->cheapest == true)
			return (a);
		a = a->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node) //Check if the required node is not already the first node
	{
		if (stack_name == 'a') //If not, and it is stack `a`, execute the following
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b') //If not, and it is stack `b`, execute the following
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}	
	}
}

void	min_on_top(t_stack **a) //Define a function that moves the smallest number to the top
{
	while ((*a)->nbr != find_min(*a)->nbr) //As long as the smallest number is not at the top
	{
		if (find_min(*a)->above_median) //Rotate or reverse rotate according to the position of the node on the median
			ra(a);
		else
			rra(a);
	}
}
