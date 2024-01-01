#ifndef CHAINED_LIST_H
# define CHAINED_LIST_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack_node
{
	int					number;
	struct s_stack_node	*next;
}	t_stack_node;

#endif