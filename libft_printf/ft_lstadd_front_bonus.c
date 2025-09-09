/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:45:51 by asergina          #+#    #+#             */
/*   Updated: 2025/06/01 16:45:53 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}

// #include "stdio.h"
// int main(void)
// {
// 	t_list *list = NULL;
// 	t_list *node1 = ft_lstnew("World");
// 	t_list *node2 = ft_lstnew("Hello");

// 	ft_lstadd_front(&list, node1);
// 	ft_lstadd_front(&list, node2);

// 	while (list != NULL)
// 	{
// 		printf("List = %s\n", (char *)list -> content);
// 		list = list -> next;
// 	}

// 	return (0);
// }
