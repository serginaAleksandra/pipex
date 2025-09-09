/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:49:36 by asergina          #+#    #+#             */
/*   Updated: 2025/05/14 16:49:40 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	i;

	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (len_d >= size)
		return (size + len_s);
	i = 0;
	while ((len_d + i + 1 < size) && src[i])
	{
		dst[len_d + i] = src[i];
		i++;
	}
	dst[len_d + i] = '\0';
	return (len_d + len_s);
}

// #include "stdio.h"
// #include "bsd/string.h"
// int main(void)
// {
//     char *src = "Bye";
//     char d1[20] = "Hello, World! ";
//     char d2[20] = "Hello, World! ";
// 	size_t i = 20;
//     size_t len;

//     len = ft_strlcat(d1, src, i);
//     printf("ft_strlcat: %zu, dst: %s\n", len, d1);
//     len = strlcat(d2, src, i);
//     printf("strlcat: %zu, dst2: %s\n", len, d2);

//     if (strcmp(d1, d2) == 0)
//         printf("Both functions return the same string.\n");
//     else
//         printf("The strings are different.\n");

//     return (0);
// }
