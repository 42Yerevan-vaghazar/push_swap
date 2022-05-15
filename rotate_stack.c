/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:40:09 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/15 15:48:05 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    rotate_stack(t_list **lst, char	*str)
{
	t_list  *tmp;
	// (void)str;

	if (!lst || !(*lst))
		return (0);
	tmp = *lst;
	*lst = (*lst) -> next;
	ft_lstadd_back(&(*lst), tmp);
	if (str)
		ft_printf("%s\n", str);
	return (1);
}