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

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a > 3 && stack_sorted(*a) == 0)
	{
		pb(b, a);
		len_a--;
	}
	if (len_a > 3 && stack_sorted(*a) == 0)
	{
		pb(b, a);
		len_a--;
	}
	while (len_a > 3 && stack_sorted(*a) == 0)
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
	current_index(*a);
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

void	current_index(t_stack *stack)
{
	int		i;
	int		median;

	i = 0;
	median = stack_len(stack) / 2;
	while (stack != NULL)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true; // why not only < and not = ? compare performance
		else
			stack->above_median = false;
		stack = stack->next;
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
		if (best_match_index == LONG_MIN)
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

t_stack	*get_cheapest(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheapest == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
///////////////////////////////////
void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node; //To store the pointer to the cheapest `a` node

	cheapest_node = get_cheapest(*a); 
	if (cheapest_node->above_median && cheapest_node->target_node->above_median) //If both the cheapest `a` node and its target `b` node are above the median
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median)) //If both the cheapest `a` node and its target `b` node are below the median
		rev_rotate_both(a, b, cheapest_node); //`rev_rotate_both` will execute if neither nodes are at the top
	prep_for_push(a, cheapest_node, 'a'); //Ensure the cheapest nodes is at the top, ready for pushing
	prep_for_push(b, cheapest_node->target_node, 'b'); //Ensure the target node is at the top, ready for pushing
	pb(b, a);
}
///////////////////////////////////
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node) //Define a function that rotates both the top `a` and `b` nodes to the bottom of their stacks, if it's the cheapest move
{
	while (*b != cheapest_node->target_node && *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node, and the current top `a` node is not the top node
		rr(a, b); //Rotate both `a` and `b` nodes
	current_index(*a);
	current_index(*b);
}
///////////////////////////////////
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node) //Define a function that rotates both the bottom `a` and `b` nodes to the top of their stacks, if it's the cheapest move
{
	while (*b != cheapest_node->target_node && *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node && and the current `a` node is not the cheapest
		rrr(a, b); //Reverse rotate both `a` and `b` nodes
	current_index(*a); //Refresh current node positions
	current_index(*b);
}
///////////////////////////////////
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name) //Define a function that moves the required node to the top of the stack
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
///////////////////////////////////
void	init_nodes_b(t_stack *a, t_stack *b) //Define a function that prepares the nodes for pushing `b` to `a`
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
///////////////////////////////////
void	set_target_b(t_stack *a, t_stack *b) //Define a function that sets for the current `a` node, its target node from stack `a`
{
	t_stack	*current_a; //To store the pointer to the current `a` node
	t_stack	*target_node; //To store the pointer of the target node for `b` node
	long			best_match_index; //To store the "closest bigger" number so far

	while (b)
	{
		best_match_index = LONG_MAX; //Set the current best match to the max long
		current_a = a; //Assign the pointer to point to the current `a` node
		while (current_a) //While the pointer is not set to NULL
		{
			if (current_a->nbr > b->nbr 
				&& current_a->nbr < best_match_index) //Check if the `a` node's value is bigger than `b` node, && smaller than the "closest bigger" so far
			{
				best_match_index = current_a->nbr; //Set the best match as the value in the current `a` node
				target_node = current_a; //Set `b` node's target node pointer to point to the current `a` node
			}
			current_a = current_a->next; //Move to the next `a` node for processing
		}
		if (best_match_index == LONG_MAX) //If the best match value has not changed
			b->target_node = find_min(a); //Set `b` node's target node pointer to point to the smallest number in stack `a`
		else
			b->target_node = target_node; //If the best match value has been updated, then we have a target node for the current `b` node
		b = b->next; //Move to the next `b` node for processing
	}
}
///////////////////////////////////
void	move_b_to_a(t_stack **a, t_stack **b) //Define a function that prepares `b`'s target `a` nodes for pushing all `b` nodes back to stack `a` 
{
	prep_for_push(a, (*b)->target_node, 'a'); //Ensure `b`'s target `a` node is on top of the stack
	pa(a, b); 
}
///////////////////////////////////
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

void	ft_sort(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	while (stack_sorted(*a) == 0)
	{
		if (stack_len(*a) == 2)
			sa(a);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else
			sort_stacks(a, &b);
	}
}

void	check_errors(char **array)
{
	int		i;
	int		nb;
	
	i = 0;
	while (array[i])
	{
		if (error_syntax(array[i]) == 1)
		{
			free(array);
			ft_error();
		}
		nb = ft_atoi(array[i]);
		if (ft_strcmp(ft_itoa(nb), array[i]) != 0)
		{
			free(array);
			ft_error();
		}
		if (error_duplicate(array, nb, i) == 1)
		{
			free(array);
			ft_error();
		}
		i++;
	}
}

t_stack	*argc_two(char **argv)
{
	t_stack	*a;
	char	**array;

	a = NULL;
	array = ft_split(argv[1], ' ');
	if (*array == NULL)
	{
		free (array);
		ft_error();
	}
	check_errors(array);
	append_stack(&a, array);
	free (array);
	return (a);
}

t_stack	*argc_more(int argc, char **argv)
{
	t_stack	*a;
	int		i;	
	char	**array;

	a = NULL;
	i = 0;
	array = malloc(sizeof(char *) * argc);
	if (array == NULL)
		return (NULL);
	while (argc > 1)
	{
		array[i] = argv[i + 1];
		i++;
		argc--;
	}
	array[i] = NULL;
	// init_stack_a(&a, array);
	check_errors(array);
	append_stack(&a, array);
	free (array);
	return (a);
}

t_stack	*ft_process(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	if (argc < 2)
		ft_error();
	if (argc == 2)
		a = argc_two(argv);
	if (argc > 2)
		a = argc_more(argc, argv);
	return (a);
}
// #include <stdio.h> 
// void	print_stack_a(t_stack *a)
// {
// 	while (a != NULL)
// 	{
// 		printf("%d\n", a->nbr);
// 		a = a->next;
// 	}
// }

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = ft_process(argc, argv);
	// print_stack_a(a);
	if (stack_sorted(a) == 0)
		ft_sort(&a);
	free_stack(&a);
	return (0);
}
