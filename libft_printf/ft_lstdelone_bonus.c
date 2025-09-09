/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asergina <asergina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:46:24 by asergina          #+#    #+#             */
/*   Updated: 2025/06/01 16:46:25 by asergina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst -> content);
	free (lst);
}

// #include <stdio.h>
// #include <stdlib.h>
// void	del_func(void *content)
// {
// 	free(content);
// }

// int main(void)
// {
// 	char	*str = ft_strdup("bad words");
// 	t_list	*node = ft_lstnew(str);

// 	printf("Before delete: %s\n", (char *)node->content);
// 	ft_lstdelone(node, del_func);
// 	printf("Deleted.\n");

// 	return 0;
// }
