/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:46:04 by asergina          #+#    #+#             */
/*   Updated: 2025/05/22 14:46:24 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*mem;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	mem = (char *)malloc(len + 1);
	if (!mem)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		mem[i] = s[i];
		i++;
	}
	return (mem);
}

// #include "stdio.h"
// #include "stdlib.h"
// #include "string.h"
// int main(void)
// {
// 	char	*str = "47gu j";
// 	char	*res1 = ft_strdup(str);
// 	char	*res2 = strdup(str);

// 	printf("ft_strdup: %s\nstrdup: %s\n", res1, res2);
// 	if (strcmp(res1, res2) == 0)
// 		printf("Both functions return the same strings.\n");
// 	else
// 		printf("The adresses are different.\n");
// 	return (0);
// }
