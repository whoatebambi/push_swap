#include "chained_list.h"

void	ft_lstadd_back(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node	*temp;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

int	main(void)
{
	t_stack_node	**lst;	
	t_stack_node	*head;
	t_stack_node	*current;
	t_stack_node	*new_node;
	int				i;

	i = 0;
	head = NULL;
	lst = &head;

	while (i < 5)
	{
		new_node = malloc(sizeof(t_stack_node));
		new_node->number = i;
		new_node->next = NULL;
		ft_lstadd_back(lst, new_node);
		i++;
	}
	
	new_node = *lst;
	while (new_node != NULL)
	{
		printf("%d\n", new_node->number);
		new_node = new_node->next;
	}
	return (0);
}