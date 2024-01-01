#include "push_swap.h"

void swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;

	first->next = second->next;  // Set the first node's next to the third node
	second->prev = first->prev;  // Set the second node's prev to NULL (as it will become the new head)
	first->prev = second;        // Set the first node's prev to the second node
	second->next = first;        // Set the second node's next to the first node
	// Adjust the third node's prev pointer, if it exists
	if (first->next) {
		first->next->prev = first;
	}
	// Update the head of the list
	*stack = second;
}

void	sa(t_stack **a)
{
	swap(a);
	printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
	printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	printf("ss\n");
}

void	rotate(t_stack **stack)
{
	t_stack *last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = find_last(*stack);
	// Point the next of the last node to the current top node
	last->next = *stack;
	// Update the top of the stack to the second node
	*stack = (*stack)->next;
	// Set the prev of the new top node to NULL
	(*stack)->prev = NULL;
	// Detach the old top node (now the last node) from the rest of the stack
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	printf("ra\n");
}

void	rb(t_stack **b)
{
	rotate(b);
	printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	printf("rr\n");
}

void	rev_rotate(t_stack **stack)
{
	t_stack *last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL; //Assign to the `next` attribute of the node before itself, `NULL` effectively setting it as the current last node
	last->next = *stack; //Assign to its own `next` attribute as the top node of the stack
	last->prev = NULL; //Detach itself from the node before it
	*stack = last;  //Complete appending itself to the top of the stack, and now holds the pointer to the top node
	last->next->prev = last; //Update the current last node of the stack
}

void	rra(t_stack **a)
{
	rev_rotate(a);
	printf("rra\n");
}

void	rrb(t_stack **b)
{
	rev_rotate(b);
	printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	printf("rrr\n");
}

void	push(t_stack **dst, t_stack **src) //Define a function that pushes a top node, from one stack to another's top node
{
	t_stack	*push_node;

	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	// push_node->prev = NULL; // pas utile normalement
	if (*dst == NULL)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;

		(*dst)->prev = push_node;
		*dst = (*dst)->prev;
		// push_node->next->prev = push_node; //Assign to the "second node" `prev` attribute, the pushed node as the current top node
		// *dst = push_node; //Complete appending the node. The pointer to the top node of the stack is now pointing to our recently pushed node
	}
}

void	pa(t_stack **a, t_stack **b) //Push on top of `b`, the top `a` and print the instruction
{
	push(a, b); 
	printf("pa\n");
}

void	pb(t_stack **b, t_stack **a) //Push on top of `a`, the top `b` and print the instruction
{
	push(b, a);
	printf("pb\n");
}