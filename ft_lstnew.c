/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:42:06 by vaghazar          #+#    #+#             */
/*   Updated: 2022/04/30 19:11:15 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*ptr;
	ptr = malloc(sizeof(ptr));
	if (!ptr)
		return (0);
	ptr -> data = content;
	ptr -> next = NULL;
	return (ptr);
}
