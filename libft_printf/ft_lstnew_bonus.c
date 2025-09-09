/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:47:05 by asergina          #+#    #+#             */
/*   Updated: 2025/06/01 16:47:07 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst -> content = content;
	lst -> next = NULL;
	return (lst);
}

// #include "stdio.h"
// int main(void)
// {
// 	char	*content = ft_strdup("Content");
// 	t_list *list = ft_lstnew(content);

// 	while (list != NULL)
// 	{
// 		printf("content = %s\n", (char *)list -> content);
// 		list = list -> next;
// 	}
// 	return (0);
// }
