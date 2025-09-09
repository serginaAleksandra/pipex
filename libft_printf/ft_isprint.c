/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:00:24 by asergina          #+#    #+#             */
/*   Updated: 2025/05/16 15:25:54 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// #include "stdio.h"
// #include "ctype.h"
// #include "stdbool.h"
// int	main()
// {
// 	int i = 0;
// 	bool j;
// 	bool k;

// 	while (i < 128)
// 	{
// 		j = ft_isprint(i);
// 		k = isprint(i);
// 		if (!j && !k)
// 			printf("ft_isprint(%d), isprint(%d)\n", i, i);
// 		if (j != k)
// 		{
// 			printf("ft_isprint(%d), isprint(%d)\n", i, i);
// 			return(1);
// 		}
// 		i++;
// 	}
// 	printf("All tests passed.\n");
// 	return (0);
// }
