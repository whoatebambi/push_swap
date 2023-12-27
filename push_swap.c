#include "push_swap.h"

int	count_words(char *str, char sep)
{
	int	word_count;
	int	i;

	word_count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		if ((str[i] != sep) && str[i])
			word_count++;
		while ((str[i] != sep) && str[i])
			i++;
	}
	return (word_count);
}

static char	*get_next_word(char *str, char sep)
{
	char		*word;
	static int	cursor;
	int			i;
	int			len;

	len = 0;
	while (str[cursor] == sep)
		cursor++;
	while ((str[cursor + len] != sep) && str[cursor + len])
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[cursor] != sep && str[cursor])	
	{
		word[i] = str[cursor];
		i++;
		cursor++;
	}
	word[i] = '\0';
	return (word);
}

char	**split(char *str, char sep)
{
	int		word_count;
	char	**result;
	int		i;

	word_count = count_words(str, sep);
	if (word_count == 0)
		return (0);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		result[i] = get_next_word(str, sep);
		i++;
	}
	result[i] = NULL;
	return (result);
}

static long	ft_atol(char *str)
{
	long		n;
	int			sign;
	int			i;
	
	sign = 1;
	i = 0;
	n = 0;
	// while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	// 	i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * sign);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

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

int	stack_len(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

static void	swap(t_stack **lst)
{
	t_stack	*head;
	t_stack	*second;
	int		tmp_nbr;

	head = *lst;
	second = head->next;
	tmp_nbr = head->nbr;
	head->nbr = second->nbr;
	second->nbr = tmp_nbr;
}
//Check if the stop node, or second node of a stack exists
//Update `head` to point to the next node, effectively swapping the first and second nodes
//Update the `prev` pointer of the node before the `new head` to point to the `new head`
//Update the `next` pointer of the node before the `new head` to skip the `old head` and point directly to the `new head`
//Check if there's a `next` node after the `new head` and
//If so, update its `prev` pointer to point back to the `new head`
//Update the `next` pointer of the `new head` to point to the `old head`, effectively reversing their positions
//Sets the `prev` pointer of the `new head` to `NULL` completing the swap

void	sa(t_stack **lst)
{
	swap(lst);
	printf("sa\n");
}

void	free_stack(t_stack **lst)
{
	t_stack	*current;
	t_stack	*tmp;

	if (!lst)
		return;
	current = *lst;
	while (current)
	{
		tmp = current->next;
		// current->nbr = 0;
		free(current);
		current = tmp;
	}
	*lst = NULL;
	exit(1);	
}

int	error_syntax(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (1);
        i++;
    }
	return (0);
}

int	error_duplicate(t_stack *a, int n)
{
	while (a != NULL)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	append_node(t_stack **a, int n)
{
	t_stack	*current;

	current = malloc(sizeof(t_stack));
	if (current == NULL)
		free_stack(a);
	current->nbr = n;
	current->next = NULL;
	ft_lstadd_back(a, current);
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_array;
	int		i;

	a = NULL;
	b = NULL;

	if (argc == 1 || (argc == 2 && argv[1] == NULL))
	{
		printf("Wrong parameters entered.");
		return (1);
	}
	else if (argc == 2)
		split_array  = split(argv[1], ' ');
	// manage if result of split = 1
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
	printf("Stack length: %d\n", stack_len(a));
	if (stack_sorted(a) == 0)
	{
		printf("Stack not sorted.\n");
		if (stack_len(a) == 2)
		{
			sa(&a);
			print_stack_a(a);
		}
		// else if (stack_len == 3)
		// 	sort_three(&a);
		// else
		// 	sort_stacks(&a, &b);
	}
	else
		printf("Stack sorted.");
	free_stack(&a);
	return (0);
}
