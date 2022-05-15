/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:45:01 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/15 15:48:33 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    reverse_rotate_stack(t_list **lst, char *str)
{
	t_list  *tmp;
	// (void)str;

	if (!lst || !(*lst) || !(*lst) -> next)
		return (0);
	tmp = *lst;
	while ((*lst) -> next -> next)
		*lst = (*lst) -> next;
	(*lst) -> next -> next = tmp;
	tmp = (*lst) -> next;
	(*lst) -> next = NULL;
	*lst = tmp;
	if (str)
		ft_printf("%s\n", str);
	return (1);
}