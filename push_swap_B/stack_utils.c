#include "push_swap.h"

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

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*find_before_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next->next)
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
///////////////////////////////////
t_stack	*find_min(t_stack *stack) //Define a function that searches a stack and returns the node with the smallest number
{
	long			min; //To store the smallest value so far
	t_stack	*min_node; //To store a pointer that points to the smallest number

	if (!stack)
		return (NULL);
	min = LONG_MAX; //Assign to the smallest value so far, the max long integer
	while (stack) //Loop until the end of the stack is reached
	{
		if (stack->nbr < min) //Check if the current node value is smaller than the smallest so far
		{
			min = stack->nbr; //If so, update the smallest number so far
			min_node = stack; //Set the pointer to point to the node with the smallest number so far
		}
		stack = stack->next; //Move to the next node for processing
	}
	return (min_node); 
}


void	append_stack(t_stack **a, char **array)
{
	t_stack	*current;
	t_stack	*last;
	int	 i = 0;

	while (array[i])
	{
		current = malloc(sizeof(t_stack));
		if (current == NULL)
			free_stack(a);
		current->nbr = ft_atoi(array[i]);
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

void	free_stack(t_stack **stack)
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
	// exit(1);	
}

// void	ft_free(t_stack **lst)
// {
// 	t_stack	*tmp;

// 	if (!lst)
// 		return ;
// 	while (*lst)
// 	{
// 		tmp = (*lst)->next;
// 		(*lst)->nbr = 0;
// 		free(*lst);
// 		*lst = tmp;
// 	}
// }