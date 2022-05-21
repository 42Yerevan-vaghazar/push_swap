/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:20:30 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/20 18:49:20 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int swap_b(t_list **a)
{
    t_list  *tmp;

    if (ft_lstsize(*a) < 2)
        return (0);
    tmp = (*a);
    (*a) = (*a) -> next;
    tmp -> next = (*a) -> next;
    (*a) -> next = tmp;
    ft_printf("sb\n");
    return (1);
}