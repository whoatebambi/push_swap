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

void	check_digit(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				error_and_exit("not a number");
			j++;
		}
		i++;
	}
}

void	check_int(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_atol(argv[i]) < INT_MIN || ft_atol(argv[i]) > INT_MAX)
			error_and_exit("not an integer");
		i++;
	}
}

void	check_duplicate(char **argv)
{
	int	i;
	int	j;
	int	temp;
	int count;

	count = 0;
	while (argv[count] != NULL)
		count++;
	if (count == 0)
		error_and_exit("empty stack");
	i = 0;
	while (i < count)
	{
		temp = ft_atoi(argv[i]);
		j = i;
		while (++j < count)
		{
			if (temp == ft_atoi(argv[j]))
				error_and_exit("duplicate value found");
		}
		i++;
	}
}

void	free_stack(t_stack **stack, int std_value)
{
	t_stack	*current;
	t_stack	*tmp;

	if (!stack)
		return;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
	if (std_value == 1)
		return ;
	error_and_exit("stack freed");
}

void	error_and_exit(char *str)
{
	// ft_putstr_fd("Error.\n", 2);
	ft_printf("Error: %s\n", str);
	exit(1);
}