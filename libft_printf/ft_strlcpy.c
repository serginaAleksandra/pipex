/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:49:52 by asergina          #+#    #+#             */
/*   Updated: 2025/05/14 16:49:55 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = 0;
	i = ft_strlen(src);
	return (i);
}

// #include "stdio.h"
// #include "bsd/string.h"
// int main(void)
// {
//     char *src = "Bye";
//     char d1[20] = "Hello, World! ";
//     char d2[20] = "Hello, World! ";
// 	size_t i = 4;
//     size_t len;

//     len = ft_strlcpy(d1, src, i);
//     printf("ft_strlcpy: %zu, dst: %s\n", len, d1);
//     len = strlcpy(d2, src, i);
//     printf("strlcpy: %zu, dst2: %s\n", len, d2);

//     if (strcmp(d1, d2) == 0)
//         printf("Both functions return the same string.\n");
//     else
//         printf("The strings are different.\n");

//     return (0);
// }