/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:47:15 by asergina          #+#    #+#             */
/*   Updated: 2025/06/01 16:47:16 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		lst = lst -> next;
		len++;
	}
	return (len);
}

// #include "stdio.h"
// int main(void)
// {
// 	t_list *list = NULL;
// 	t_list *node1 = ft_lstnew("One");
// 	t_list *node2 = ft_lstnew("Two");
// 	t_list *node3 = ft_lstnew("Three");
//
// 	printf("Size (empty): %d\n", ft_lstsize(list)); 
// 	ft_lstadd_front(&list, node1);
// 	printf("Size (1 node): %d\n", ft_lstsize(list));
// 	ft_lstadd_front(&list, node2);
// 	printf("Size (2 nodes): %d\n", ft_lstsize(list));
// 	ft_lstadd_front(&list, node3);
// 	printf("Size (3 nodes): %d\n", ft_lstsize(list));
// 	while (list)
// 	{
// 		t_list *tmp = list;
// 		list = list->next;
// 		free(tmp);
// 	}
//
// 	return (0);
// }
