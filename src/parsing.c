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

void	single_argv_to_array(char ***argv)
{
	*argv = ft_split((*argv)[1], ' ');
	if (*argv == NULL)
	{
		free(*argv);
		error_and_exit("split failed");
	}
}

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

void	append_stack(t_stack **a, char **argv)
{
	t_stack	*current;
	t_stack	*last;
	int	 i;
	
	i = 0;
	while (argv[i])
	{
		current = malloc(sizeof(t_stack));
		if (current == NULL)
			free_stack(a, 2);
		current->nbr = ft_atoi(argv[i]);
		current->next = NULL;
		if (*a == NULL)
			*a = current;
		else
		{
			last = find_last(*a);
			last->next = current;
		}
		i++;
	}
}

t_stack	*parse_stack(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	if (argc < 2)
		error_and_exit("not enough arguments");
	if (argc == 2)
		single_argv_to_array(&argv);
	check_digit(argv);
	check_int(argv);
	check_duplicate(argv);
	append_stack(&a, argv);
	int	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
	return (a);
}

void	error_and_exit(char *str)
{
	// ft_putstr_fd("Error.\n", 2);
	ft_printf("Error: %s\n", str);
	exit(1);
}