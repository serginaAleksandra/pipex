/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:26:41 by asergina          #+#    #+#             */
/*   Updated: 2025/05/16 15:26:44 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_d;
	const unsigned char	*ptr_s;

	if (dest == src || n == 0)
		return (dest);
	ptr_d = (unsigned char *)dest;
	ptr_s = (const unsigned char *)src;
	if (ptr_s < ptr_d)
	{
		ptr_d += n;
		ptr_s += n;
		while (n--)
			*--ptr_d = *--ptr_s;
	}
	else
		return (ft_memcpy(dest, src, n));
	return (dest);
}

// #include "stdio.h"
// #include "string.h"
// int main(void)
// {
// 	char src[20] = "sch dfr";
// 	size_t i = 3;
// 	char *d1 = src + 3;
// 	char *d2 = src + 3;

// 	ft_memmove(src + 3, src, i);
// 	memmove(src + 3, src, i);
// 	printf("ft_memmove: %s\nmemmove: %s\n", d1, d2);
// 	if (memcmp(d1, d2, 10) == 0)
// 		printf("Both functions return the same string.\n");
// 	else
//         printf("The strings are different.\n");
// 	return (0);
// }
