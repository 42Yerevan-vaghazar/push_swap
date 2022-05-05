/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:40:09 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/01 10:36:24 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    rotate_stack(t_list **lst)
{
	t_list  *tmp;

	if (!lst || !(*lst))
		return (0);
	tmp = *lst;
	*lst = (*lst) -> next;
	ft_lstadd_back(&(*lst), tmp);
	return (1);
}