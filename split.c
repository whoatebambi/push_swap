// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>

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
	int		j;

	word_count = count_words(str, sep);
	if (word_count == 0)
		return (0);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (result == NULL)
		return (NULL);
	j = 0;
	while (j < word_count)
	{
		result[j] = get_next_word(str, sep);
		j++;
	}
	result[j] = NULL;
	return (result);
}

int	main(void)
{
	char	*str;
	char	sep;
	char	**result;
	int		i;
	int		word_count;

	str = "Hello humans of earth!";
	sep = ' ';

	printf("str = %s\n", str);
	printf("c = '%c'\n", sep);

	word_count = 0;
	word_count = count_words(str, sep);
	printf("word_count = %d\n", word_count);

	result = split(str, sep);
	i = 0;
	while (result[i])
	{
		printf("word = %s\n", result[i]);
		i++;
	}
	return (0);
}