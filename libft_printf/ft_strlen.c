/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:00:24 by asergina          #+#    #+#             */
/*   Updated: 2025/05/13 13:05:47 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

// #include "stdio.h"
// #include "string.h"
// int main(void)
// {
//     char *str = "Bye!";
//     size_t len1 = ft_strlen(str);
//     size_t len2 = strlen(str);

//     printf("ft_strlen: %zu\nstrlen: %zu\n", len1, len2);

//     if (len1 == len2)
//         printf("Both functions return the same length.\n");
//     else
//         printf("The lengths are different.\n");

//     return 0;
// }