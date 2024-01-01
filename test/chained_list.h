#ifndef CHAINED_LIST_H
# define CHAINED_LIST_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

#endif