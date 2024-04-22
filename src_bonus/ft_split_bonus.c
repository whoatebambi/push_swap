/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:33:43 by fcouserg          #+#    #+#             */
/*   Updated: 2023/11/10 18:34:28 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"
#include <stdio.h>

static size_t	fts_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static size_t	fts_wordlen(char const *s, char c, size_t i)
{
	size_t	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static char	**fts_wordsplit(char const *s, char c, char **result, size_t word)
{
	size_t	a;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	a = 0;
	while (a < word)
	{
		while (s[i] == c)
			i++;
		len = fts_wordlen(s, c, i);
		result[a] = (char *)malloc(sizeof(char) * (len + 1));
		if (!result)
			return (NULL);
		j = 0;
		while (j < len)
			result[a][j++] = s[i++];
		result[a][j] = '\0';
		a++;
	}
	result[a] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word;

	if (!s)
		return (NULL);
	word = fts_wordcount(s, c);
	// printf("words: %ld\n", word);
	result = (char **)malloc((word + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result = fts_wordsplit(s, c, result, word);
	return (result);
}

// int	main(void)
// {
// 	char	*str;
// 	char	**array;
// 	int		i;

// 	str = " 1 6 4 3";
// 	i = 0;

// 	array = ft_split(str, ' ');
// 	while (array[i])
// 	{
// 		printf("%s\n", array[i]);
// 		i++;
// 	}
		
// 	printf("TEST\n");

// 	return (0);
// }