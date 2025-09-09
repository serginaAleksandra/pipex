/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:00:24 by asergina          #+#    #+#             */
/*   Updated: 2025/05/16 15:24:46 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((ft_isalpha(c)) || (ft_isdigit(c)));
}

// #include "stdio.h"
// #include "ctype.h"
// #include "stdbool.h"
//  int	main(void)
// {
// 	int i = 0;
//     bool j;
//     bool k;

//     while (i < 256)
//     {
//         j = ft_isalpha(i);
//         k = isalpha(i);
//         if (j != k)
//         {
//             printf("ft_isalpha(%d), isalpha(%d) \n", i, i);
//             return (1);
//         }
//         i++;
//     }
//     printf("All tests passed.\n");
//     return (0);
// }
