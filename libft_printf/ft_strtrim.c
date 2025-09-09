/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:37:58 by asergina          #+#    #+#             */
/*   Updated: 2025/05/26 13:38:05 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (ft_inset(s1[i], set) && s1[i])
		i++;
	len = ft_strlen(s1);
	if (i == len)
		return (ft_strdup(""));
	while (ft_inset(s1[len - 1], set) && len > i)
		len--;
	return (ft_substr(s1, i, len - i));
}

// #include "stdio.h"
// int main(void)
// {
//     char    *str1 = "abcdeifg";
//     char    *tr = "ifgabcde";
//     printf("The string to be trimmed: %s\n", str1);
//     printf("The set of characters to remove: %s\n", tr);
//     printf("New string: %s\n", ft_strtrim(str1, tr));
//     return (0);
// }