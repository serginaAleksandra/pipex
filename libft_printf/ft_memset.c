/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:00:24 by asergina          #+#    #+#             */
/*   Updated: 2025/05/16 15:26:57 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		*ptr = (unsigned char)c;
		ptr++;
	}
	return (s);
}

// #include "stdio.h"
// #include "string.h"
// int main(void)
// {
// 	char str1[20] = "Fg jid4s";
// 	char str2[20] = "Fg jid4s";
// 	char c = '+';
// 	size_t i = 4;

// 	ft_memset(str1, c, i);
// 	memset(str2, c, i);
// 	printf("ft_memset: %s\nmemset: %s\n", str1, str2);
// 	if (memcmp(str1, str2, 10) == 0)
// 		printf("Both functions return the same string.\n");
// 	else
//         printf("The strings are different.\n");
// 	return (0);
// }