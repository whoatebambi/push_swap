#include "push_swap.h"

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

int	stack_sorted(t_stack *a)
{
	while (a != NULL && a->next != NULL)
	{
		if (a->nbr > a->next->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

void	init_stack_a(t_stack **a, char **split_array)
{
	int		i;
	long	n;
	
	i = 0;
	while (split_array[i])
	{
		if (error_syntax(split_array[i]) == 1)
		{
			printf("Syntax error.\n");
			free_stack(a);
		}
		n = ft_atol(split_array[i]);
		if (n < INT_MIN || n > INT_MAX)
		{
			printf("Int overflow error.\n");
			free_stack(a);
		}
		if (error_duplicate(*a, n) == 1)
		{
			printf("Duplicates error.\n");
			free_stack(a);
		}
		append_node(a, (int)n);
		i++;
	}
}

void	print_stack_a(t_stack *a)
{
	while (a != NULL)
	{
		printf("%d\n", a->nbr);
		a = a->next;
	}
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(a);
	if (len_a > 3 && stack_sorted(a) == 0)
	{
		pb(&b, &a);
		len_a--;
	}
	if (len_a > 3 && stack_sorted(a) == 0)
	{
		pb(&b, &a);
		len_a--;
	}
	while (len_a > 3 && stack_sorted(a) == 0)
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(a);
	min_on_top(a);
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}

void	current_index(t_stack **stack)
{
	t_stack	*current; // try to remove * one ponter level and use only stack
	int		i;
	int		median;

	i = 0;
	median = stack_len(stack) / 2;
	current = *stack;
	while (current != NULL)
	{
		current->index = i;
		if (i <= median)
			current->above_median = true; // why not only < and not = ? compare performance
		else
			current->above_median = false;
		current = current->next;
		i++;
	}
}

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack *current_b;
	t_stack	*target_node;
	long	best_match_index;

	best_match_index = LONG_MIN;
	while (a)
	{
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				target_node = current_b;
			}	
			current_b = current_b->next;
		}
		if (best_match_index = LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	cost_analysis_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (a->above_median == false)
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median == true)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	cheapest_value = LONG_MAX;
	while (stack != NULL)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}
void	move_a_to_b(t_stack **a, t_stack **b)
{
	
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_array;
	int		i;

	a = NULL;
	b = NULL;
	split_array = NULL;

	if (argc == 1 || (argc == 2 && argv[1] == NULL))
	{
		printf("Wrong parameters entered.");
		return (1);
	}
	else if (argc == 2)
		split_array  = split(argv[1], ' ');
	else
	{
		i = 1;
		while (argv[i])
		{
			split_array[i - 1] = argv[i];
			i++;
		}
	}
	init_stack_a(&a, split_array);
	print_stack_a(a);
	while (stack_sorted(a) == 0)
	{
		printf("Stack not sorted.\n");
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}

	if (stack_sorted(a) == 1)
	{
		printf("Stack sorted.\n");
		print_stack_a(a);
	}
	free_stack(&a);
	return (0);
}
