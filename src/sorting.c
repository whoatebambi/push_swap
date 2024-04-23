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

int	check_sorting(t_stack *a)
{
	while (a != NULL && a->next != NULL)
	{
		if (a->nbr > a->next->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_three(t_stack **a)
{
	t_stack *biggest;

	biggest = find_max(*a);
	if (*a == biggest)
		ra(a);
	else if ((*a)->next == biggest)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	sort_stacks(t_stack **a, t_stack **b) ////////////////////////////
{
	int		len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && check_sorting(*a) == 0)
		pb(b, a);
	if (len_a-- > 3 && check_sorting(*a) == 0)
		pb(b, a);
	while (len_a-- > 3 && check_sorting(*a) == 0)
	{
		init_stack_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b != NULL)
	{
		init_stack_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
	// int i = 0;
	// while(*a)
	// {
	// 	printf("a[%d]-nbr: %d  | index: %d  | cost: %d  | target: b[%d]-nbr: %d\n", i++, (*a)->nbr, (*a)->index, (*a)->push_cost, (*a)->target->index, (*a)->target->nbr);
	// 	(*a) = (*a)->next;
	// }
	// printf("-----\n");
	// i = 0;
	// while(*b)
	// {
	// 	printf("b[%d]-nbr: %d  | index: %d\n", i++, (*b)->nbr, (*b)->index);
	// 	(*b) = (*b)->next;
	// }
}

void	init_stack_a(t_stack *a, t_stack *b) ////////////////////////////
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);	
}

void	init_stack_b(t_stack *a, t_stack *b) ////////////////////////////
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target;
	long	closest_sup_nb_of_a;

	while (b != NULL)
	{
		current_a = a;
		closest_sup_nb_of_a = LONG_MAX;
		while (current_a != NULL)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < closest_sup_nb_of_a)
			{
				closest_sup_nb_of_a = current_a->nbr;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (closest_sup_nb_of_a == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	current_index(t_stack *stack) ////////////////////////////
{
	int	index;
	int	len;

	index = 0;
	len = stack_len(stack);
	while (stack != NULL)
	{
		stack->index = index++;
		if (index < len / 2)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
	}
}

void	set_target_a(t_stack *a, t_stack *b) ////////////////////////////
{
	t_stack	*current_b;
	t_stack	*target;
	long	closest_inf_nb_of_a;

	while (a != NULL)
	{
		current_b = b;
		closest_inf_nb_of_a = LONG_MIN;
		while (current_b != NULL)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > closest_inf_nb_of_a)
			{
				closest_inf_nb_of_a = current_b->nbr;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (closest_inf_nb_of_a == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	cost_analysis_a(t_stack *a, t_stack *b) ////////////////////////////
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a != NULL)
	{
		a->push_cost = a->index;
		if (a->above_median == false)
			a->push_cost = len_a - (a->index);
		if (a->target->above_median == true)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - (a->target->index);
		a = a->next;
	}
}

void	set_cheapest(t_stack *a) ////////////////////////////
{
	t_stack	*cheapest_node;
	long		cheapest_cost;

	cheapest_cost = LONG_MAX;
	while (a != NULL && a->next != NULL)
	{
		if (a->push_cost < cheapest_cost)
		{
			cheapest_cost = a->push_cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	cheapest_node->cheapest = true;
	// printf("cheapest_node: a[%d] | %d\n", cheapest_node->index, cheapest_node->nbr);
}

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