/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:29:55 by asergina          #+#    #+#             */
/*   Updated: 2025/05/16 15:29:56 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

// #include "stdio.h"
// #include "ctype.h"
// #include "string.h"

// int main (void)
// {
// 	char *str = "2uPpER?";
// 	char result1[20];
// 	char result2[20];
// 	int i = 0;

// 	while (str[i])
// 	{
// 		result1[i] = ft_toupper(str[i]);
// 		result2[i] = toupper(str[i]);
// 		i++;
// 	}
// 	printf("ft_toupper: %s\ntoupper: %s\n", result1, result2);
// 	if (strcmp(result1, result2) == 0)
// 		printf("Both functions return the same string.\n");
// 	else
// 		printf("The strings are different.\n");

// 	return (0);
// }