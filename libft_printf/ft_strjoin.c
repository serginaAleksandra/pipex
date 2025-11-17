/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandra <aleksandra@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:33:44 by asergina          #+#    #+#             */
/*   Updated: 2025/11/17 08:10:25 by aleksandra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	 if (!s1 || !s2)
        return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(len1 + len2 + 1);
	if (!str)
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
