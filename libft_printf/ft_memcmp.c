/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:26:19 by asergina          #+#    #+#             */
/*   Updated: 2025/05/16 15:26:21 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
	}
	return (0);
}

// #include "stdio.h"
// #include "string.h"
// int main(void)
// {
// 	char str1[20] = "ab f vjiE Ed";
// 	char str2[20] = "ab s vjiE Ed";
// 	size_t i = 4;

// 	int j = ft_memcmp(str1, str2, i);
// 	int k = memcmp(str1, str2, i);
// 	printf("ft_memcmp: %i\nmemcmp: %i\n", j, k);
// 	if (j == k)
// 		printf("Both functions return the same value.\n");
// 	else
//         printf("The functions are different.\n");
// 	return (0);
// }