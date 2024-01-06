#include "chained_list.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new_node)
{
	t_stack	*temp;

	if (*lst == NULL)
	{
		new_node->prev = NULL;
		*lst = new_node;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	new_node->prev = temp;
	temp->next = new_node;
}
void	create_list(t_stack **lst, int value)
{
	int				i;
	t_stack	*new_node;

	i = 0;
	while (i < 5)
	{
		new_node = malloc(sizeof(t_stack));
		new_node->number = value;
		new_node->next = NULL;
		ft_lstadd_back(lst, new_node);
		i++;
	}
}

void	print_stack(t_stack *lst)
{
	while (lst != NULL)
	{
		printf("%d - ", lst->number);
		printf("%d\n", lst->index);
		lst = lst->next;
	}
}

void	add_index(t_stack **lst)
{
	int i = 1;
	t_stack	*current;

	current = *lst;
	while (current != NULL)
	{
		current->index = i;
		current = current->next;
		i++;
	}
}

void	push(t_stack **dst, t_stack **src)
{
	t_stack	*push_node;

	push_node = *src;

	*src = (*src)->next;
	(*src)->prev = NULL;

	(*dst)->prev = push_node;
	push_node->next = *dst;
	*dst = (*dst)->prev;
}

int	main(void)
{
	t_stack	*a;	
	t_stack	*b;

	a = NULL;
	b = NULL;
	
	create_list(&a, 99);
	create_list(&b, 11);
	// print_stack(lst);
	add_index(&a);
	add_index(&b);
	// print_stack(a);
	// printf("\n%d\n", lst->next->prev->index);
	push(&b, &a);
	print_stack(b);
	return (0);
}