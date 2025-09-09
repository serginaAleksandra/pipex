/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:30:07 by asergina          #+#    #+#             */
/*   Updated: 2025/05/16 15:30:10 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

// #include "stdio.h"
// #include "ctype.h"
// #include "string.h"

// int main (void)
// {
// 	char *str = "2LoWEr?";
// 	char result1[20];
// 	char result2[20];
// 	int i = 0;

// 	while (str[i])
// 	{
// 		result1[i] = ft_tolower(str[i]);
// 		result2[i] = tolower(str[i]);
// 		i++;
// 	}
// 	printf("ft_tolower: %s\ntolower: %s\n", result1, result2);
// 	if (strcmp(result1, result2) == 0)
// 		printf("Both functions return the same string.\n");
// 	else
// 		printf("The strings are different.\n");

// 	return (0);
// }