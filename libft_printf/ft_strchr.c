/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:27:07 by asergina          #+#    #+#             */
/*   Updated: 2025/05/16 15:27:09 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

// #include "stdio.h"
// #include "string.h"
// int main(void)
// {
//     char *str = "Hello, World!";
//     char c = 'o';
//     char *result1 = ft_strchr(str, c);
//     char *result2 = strchr(str, c);

//     printf("ft_strchr: %s\nstrchr: %s\n", result1, result2);
//     if (strcmp(result1, result2) == 0)
// 		printf("Both functions return the same string.\n");
// 	else
//         printf("The strings are different.\n");

//     return (0);
// }