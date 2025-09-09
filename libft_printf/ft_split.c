/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 22:01:11 by asergina          #+#    #+#             */
/*   Updated: 2025/05/30 22:01:13 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*ft_word_copy(char const *s, char c)
{
	size_t	i;
	char	*word;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(i + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, i + 1);
	return (word);
}

static int	ft_fill(char const *s, char c, char **word, size_t words)
{
	size_t	i;

	i = 0;
	while (i < words && *s)
	{
		while (*s && *s == c)
			s++;
		word[i] = ft_word_copy(s, c);
		if (!word[i])
		{
			while (i > 0)
			{
				i--;
				free(word[i]);
			}
			free(word);
			return (0);
		}
		while (*s && *s != c)
			s++;
		i++;
	}
	word[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**word;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	word = (char **)malloc((words + 1) * (sizeof(char *)));
	if (!word)
		return (NULL);
	if (!ft_fill(s, c, word, words))
		return (NULL);
	return (word);
}

// #include "stdio.h"
// int main(void)
// {
// 	char    *s = "&";
// 	char    c = '&';
// 	char	**res = ft_split(s, c);
// 	size_t	i = 0;

// 	printf("The string to be split: %s\nThe delimiter character: %c\n", s, c);

// 	while (res[i])
// 	{
// 		printf("Word: %s\n", res[i]);
// 		i++;
// 	}
// 	printf("Word: %s\n", res[i]);
// 	while (i > 0)
// 		free(res[--i]);
// 	return (0);
// }
