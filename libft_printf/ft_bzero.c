/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:00:24 by asergina          #+#    #+#             */
/*   Updated: 2025/05/16 15:24:26 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		*ptr = '\0';
		ptr++;
	}
}
/*
#include "stdio.h"
#include "string.h"
int main(void)
{
	char *str1 = "Ade 67U d";
	char *str2 = "Ade 67U d";
	size_t i = 6;

	ft_bzero(str1, i);
	bzero(str2, i);
	if (memcmp(str1, str2, 10) == 0)
		printf("Both functions return the same string.\n");
	else
        printf("The strings are different.\n");
	return (0);
}
*/