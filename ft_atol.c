// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>

#include "push_swap.h"

static long	ft_atol(char *str)
{
	long		n;
	int		sign;
	int		i;
	
	sign = 1;
	i = 0;
	n = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
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

// int	main(void)
// {
// 	char		*str;
// 	long		n;

// 	str = "-42";
// 	n = ft_atol(str);

// 	printf("str : %s\n", str);
// 	printf("n   : %ld\n", n);

// 	return (0);
// }