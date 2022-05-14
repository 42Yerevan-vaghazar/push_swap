/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:18:59 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/14 14:49:30 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int swap_a(t_list **a)
{
    t_list  *tmp;

    if (ft_lstsize(*a) < 2)
        return (0);
    tmp = (*a);
    (*a) = (*a) -> next;
    tmp -> next = (*a) -> next;
    (*a) -> next = tmp;
    ft_printf("sa\n");
    return (1);
}