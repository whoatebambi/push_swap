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

void	init_stack_b(t_stack *a, t_stack *b)
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
