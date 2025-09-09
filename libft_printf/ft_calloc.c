/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:22:55 by asergina          #+#    #+#             */
/*   Updated: 2025/05/22 11:23:48 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (nmemb > __SIZE_MAX__ / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(void)
{
    size_t i = 7;
    size_t b = sizeof(int);
    void *res1 = ft_calloc(i, b);
    void *res2 = calloc(i, b);

    printf("ft_calloc: %p\ncalloc: %p\n", res1, res2);
    if (memcmp(res1, res2, i * b) == 0)
		printf("Both functions return the same adress.\n");
	else
        printf("The adresses are different.\n");
    return (0);
}
*/
