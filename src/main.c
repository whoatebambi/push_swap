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

int	main(int argc, char **argv)
{
	t_stack	*a;
	// t_stack	*b;

	a = NULL;
	// b = NULL;
	a = parse_stack(argc, argv);
	// init_stack(&a);
	if (check_sorting(a) == 0)
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
		{
			printf("len = %d\n", stack_len(a));//sort_stacks(&a, &b);
			// min_on_top(a);
		}
	}
	print_stack(a);
	free_stack(&a, 1);
	return (0);
}
