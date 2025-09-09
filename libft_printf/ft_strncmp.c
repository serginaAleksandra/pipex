/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:28:47 by asergina          #+#    #+#             */
/*   Updated: 2025/05/16 15:28:49 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// #include "stdio.h"
// #include "string.h"
// int main(void)
// {
//     char str1[20] = "Bye  World!";
//     char str2[20] = "ByeK World!";
// 	size_t i = 6;

//     int result1 = ft_strncmp(str1, str2, i);
//     int result2 = strncmp(str1, str2, i);
//     printf("ft_strncmp: %i\nstrncmp: %i\n", result1, result2);

//     if (result1 == result2)
//         printf("Both functions return the same string.\n");
//     else
//         printf("The strings are different.\n");

//     return (0);
// }