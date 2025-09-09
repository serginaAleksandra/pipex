/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:00:24 by asergina          #+#    #+#             */
/*   Updated: 2025/05/16 15:25:43 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// #include "stdio.h"
// #include "ctype.h"
// #include "stdbool.h"
// int	main()
// {
// 	int i = 0;
// 	bool j;
// 	bool k;

// 	while (i < 256)
// 	{
// 		j = ft_isdigit(i);
// 		k = isdigit(i);
// 		if (j != k)
// 		{
// 			printf("ft_isdigit(%d), isdigit(%d)\n", i, i);
// 			return(1);
// 		}
// 		i++;
// 	}
// 	printf("All tests passed.\n");
// 	return (0);
// }
