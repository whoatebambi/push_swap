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

void	sort_stacks(t_stack **a, t_stack **b)
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
}
