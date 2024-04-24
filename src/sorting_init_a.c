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

void	init_stack_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);	
}

void	current_index(t_stack *stack)
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

void	set_target_a(t_stack *a, t_stack *b)
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

void	cost_analysis_a(t_stack *a, t_stack *b)
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

void	set_cheapest(t_stack *a)
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
}
