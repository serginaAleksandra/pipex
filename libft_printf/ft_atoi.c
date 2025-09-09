/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:23:36 by asergina          #+#    #+#             */
/*   Updated: 2025/05/16 15:24:02 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;
	int	i;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *str = "   	 -442f*4d";
	int result1 = ft_atoi(str);
	int result2 = atoi(str);
	printf("ft_atoi: %i\natoi: %i\n", result1, result2);
	if (result1 == result2)
	printf("Both functions return the same value.\n");
	else
	printf("The functions are different.\n");

	return (0);
}
*/