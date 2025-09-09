/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:33:44 by asergina          #+#    #+#             */
/*   Updated: 2025/05/26 12:33:46 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(len1 + len2 + 1);
	if (!s1 || !s2 || !str)
		return (NULL);
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2 + 1);
	return (str);
}

// #include "stdio.h"
// int main(void)
// {
//     char    *str1;
//     char    *str2 = "'m Sasha";

//     printf("The prefix string: %s\nThe sufix string: %s\n", str1, str2);
//     printf("New string: %s\n", ft_strjoin(str1, str2));
//     return (0);
// }
