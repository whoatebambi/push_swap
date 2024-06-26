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

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max_node;
	long	max_nbr;

	// if (!stack)
	// 	return (NULL);
	max_node = stack;
	max_nbr = LONG_MIN;
	while (stack != NULL)
	{
		if (stack->nbr > max_nbr)
		{
			max_nbr = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min_node;
	long	min_nbr;

	// if (!stack)
	// 	return (NULL);
	min_node = stack;
	min_nbr = LONG_MAX;
	while (stack != NULL)
	{
		if (stack->nbr < min_nbr)
		{
			min_nbr = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack	*find_before_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

int	stack_len(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}


