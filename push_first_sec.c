/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_first_sec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:17:53 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/13 18:46:25 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    push_first_sec(t_list **a, t_list **b)
{
    t_list  *tmp;
    if (!(*a))
        return (0);
    tmp = *a;
    *a = (*a) -> next;
	tmp -> next = *b;
    (*b) = tmp;
    return (1);
}