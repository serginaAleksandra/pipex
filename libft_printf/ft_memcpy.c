/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:26:30 by asergina          #+#    #+#             */
/*   Updated: 2025/05/16 15:26:32 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_d;
	const unsigned char	*ptr_s;

	if (!dest && !src)
		return (NULL);
	ptr_d = (unsigned char *)dest;
	ptr_s = (const unsigned char *)src;
	while (n--)
		*ptr_d++ = *ptr_s++;
	return (dest);
}

// #include "stdio.h"
// #include "string.h"
// int main(void)
// {
// 	char d1[20] = "00 ft";
// 	char d2[20] = "00 ft";
// 	char src[20] = "sch dfr";
// 	size_t i = 6;

// 	ft_memcpy(d1, src, i);
// 	memcpy(d2, src, i);
// 	printf("ft_memcpy: %s\nmemcpy: %s\n", d1, d2);
// 	if (memcmp(d1, d2, 10) == 0)
// 		printf("Both functions return the same string.\n");
// 	else
//         printf("The strings are different.\n");
// 	return (0);
// }
