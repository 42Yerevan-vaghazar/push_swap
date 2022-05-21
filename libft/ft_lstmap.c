/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:41:41 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/21 17:49:12 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*node;
// 	t_list	*new_node;
// 	t_list	*tmp;

// 	node = ft_lstnew(f(lst -> content));
// 	if (!node)
// 		return (NULL);
// 	new_node = node;
// 	lst = lst -> next;
// 	while (lst)
// 	{
// 		tmp = ft_lstnew(f(lst -> content));
// 		if (!tmp)
// 			ft_lstclear(&new_node, del);
// 		node -> next = tmp;
// 		node = node -> next;
// 		lst = lst -> next;
// 	}
// 	return (new_node);
// }
