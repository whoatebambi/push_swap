#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include <string.h>


int	ft_atoi(char *str)
{
	int			n;
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

int	s_isneg(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

int	s_intlen(unsigned int nbr)
{
	size_t	i;

	if (nbr == 0)
		return (1);
	i = 0;
	while (nbr >= 1)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	len;
	unsigned int	neg;
	unsigned int	nbr;

	neg = s_isneg(n);
	if (neg)
		nbr = -n;
	else
		nbr = n;
	len = s_intlen(nbr);
	str = (char *)malloc(sizeof(char) * (len + neg + 1));
	if (!str)
		return (NULL);
	if (neg == 1)
		str[0] = '-';
	str[len + neg] = '\0';
	while (len > 0)
	{
		str[(len - 1) + neg] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	int		nb;

	char	*itoa_nb;

	nb = atoi(argv[1]);

	itoa_nb = ft_itoa(nb);

	if (strcmp(itoa_nb, argv[1]) == 0)
		printf("SAME INT\n");
	else
		printf("OVERFLOW\n");
	return (0);
}