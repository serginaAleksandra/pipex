/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:29:14 by asergina          #+#    #+#             */
/*   Updated: 2025/05/16 15:29:15 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		while (little[j] && big[i + j] == little[j] && (i + j) < len) 
			j++;
		if (!little[j])
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}

// #include "stdio.h"
// #include "bsd/string.h"
// int main (void)
// {
// 	char *big = "main string";
// 	char *lit = "in str";
// 	size_t i = 8;
// 	char *result1 = ft_strnstr(big, lit, i);
//     char *result2 = strnstr(big, lit, i);

//     printf("ft_strnstr: %s\nstrnstr: %s\n", result1, result2);
//     if (strcmp(result1, result2) == 0)
// 		printf("Both functions return the same string.\n");
// 	else
//         printf("The strings are different.\n");

//     return (0);
// }