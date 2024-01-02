#include "push_swap.h"

// // my precious split with static variable
// int	count_words(char *str, char sep)
// {
// 	int	word_count;
// 	int	i;
// 	word_count = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		while (str[i] == sep)
// 			i++;
// 		if ((str[i] != sep) && str[i])
// 			word_count++;
// 		while ((str[i] != sep) && str[i])
// 			i++;
// 	}
// 	return (word_count);
// }
// char	*get_next_word(char *str, char sep)
// {
// 	char		*word;
// 	static int	cursor;
// 	int			i;
// 	int			len;
// 	len = 0;
// 	while (str[cursor] == sep)
// 		cursor++;
// 	while ((str[cursor + len] != sep) && str[cursor + len])
// 		len++;
// 	word = malloc(sizeof(char) * (len + 1));
// 	if (word == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (str[cursor] != sep && str[cursor])	
// 	{
// 		word[i] = str[cursor];
// 		i++;
// 		cursor++;
// 	}
// 	word[i] = '\0';
// 	return (word);
// }
// char	**split(char *str, char sep)
// {
// 	int		word_count;
// 	char	**result;
// 	int		i;
// 	word_count = count_words(str, sep);
// 	if (word_count == 0)
// 		exit (printf("Error\n"));
// 	result = malloc(sizeof(char *) * (word_count + 1));
// 	if (result == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (i < word_count)
// 	{
// 		result[i] = get_next_word(str, sep);
// 		i++;
// 	}
// 	result[i] = NULL;
// 	return (result);
// }

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
void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

int	error_duplicate(char **array, int nb, int i)
{
	int	j;

	j = 0;
	
	while (array[j] != NULL && j < i)
	{
		if (ft_atoi(array[j]) == nb)
			return (1);
		j++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int		n;
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

int	ft_strcmp(const char *s1, const char *s2)
{
	while ((unsigned char)*s1 == (unsigned char)*s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}