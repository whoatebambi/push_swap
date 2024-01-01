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
void	append_node(t_stack **a, int n)
{
	t_stack	*current;
	t_stack	*last;

	current = malloc(sizeof(t_stack));
	if (current == NULL)
		free_stack(a);
	current->nbr = n;
	current->next = NULL;

	if (*a == NULL)
	{
		*a = current;
		current->prev = NULL;
	}
	else
	{
		last = find_last(*a);
		last->next = current;
		current->prev = last;
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
		// current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
	exit(1);	
}