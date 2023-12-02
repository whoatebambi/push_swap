#include <stdio.h>
#include "libftpush_swap.h"

static int	ft_strisdigit(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' && (str[i + 1] >= '1' && str[i + 1] <= '9')) || (str[i] >= '0' && str[i] <= '9'))
		i++;
	else
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

t_list	*ft_lst_get_last(t_list *stash)
{
	t_list	*current;

	current = stash;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	add_to_stash(t_list **stash_a, char *argv)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	*stash_a = new_node;	
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (ft_strlen(argv) + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (argv[i])
	{
		new_node->content[i] = argv[i];
		i++;
	}
	new_node->content[i] = '\0';
	last = ft_lst_get_last(*stash_a);
	last->next = new_node;
}

void	push_swap(char *argv, int argc)
{
	t_list *stash_a = NULL;
	add_to_stash(&stash_a, argv);
	t_list current = *stash_a;
	while (stash_a != NULL)
	{
		printf("%s\n", current->content);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	if (argc <= 1)
		return (0);
	// Run push_swap with non numeric parameters. The program must display "Error".
	i = 1;
	while (i < argc)
	{
		if (ft_strisdigit(argv[i]) == 0)
		{
			printf("Error\n");
			return (-1);
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		push_swap(argv[i], argc);
		i++;
	}

	// Run push_swap with a duplicate numeric parameter. The program must display "Error".
	// Run push_swap with only numeric parameters including one greater than MAXINT. The program must display "Error".

	return (0);
}