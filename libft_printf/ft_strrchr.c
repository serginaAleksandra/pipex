/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:29:39 by asergina          #+#    #+#             */
/*   Updated: 2025/05/16 15:29:42 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)last);
}

// #include "stdio.h"
// #include "string.h"
// int main(void)
// {
//     char *str = "Hello, World!";
//     char c = 'l';
//     char *result1 = ft_strrchr(str, c);
//     char *result2 = strrchr(str, c);

//     printf("ft_strrchr: %s\nstrrchr: %s\n", result1, result2);
//     if (strcmp(result1, result2) == 0)
// 		printf("Both functions return the same string.\n");
// 	else
//         printf("The strings are different.\n");

//     return 0;
// }