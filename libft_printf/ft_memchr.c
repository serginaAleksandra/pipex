/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:26:08 by asergina          #+#    #+#             */
/*   Updated: 2025/05/16 15:26:10 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;

	ptr = (const unsigned char *)s;
	while (n--)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}

// #include "stdio.h"
// #include "string.h"
// int main(void)
// {
// 	char str[20] = "Fg jid4is";
// 	char c = '4';
// 	size_t i = 7;

// 	char *res1 = ft_memchr(str, c, i);
// 	char *res2 = memchr(str, c, i);
// 	printf("ft_memchr: %p\nmemchr: %p\n", res1, res2);
// 	if (res1 == res2)
// 		printf("Both functions return the same adress.\n");
// 	else
//         printf("The adresses are different.\n");
// 	return (0);
// }