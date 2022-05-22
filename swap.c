/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:18:59 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/22 14:43:21 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int swap(t_list **a, char *s)
{
    t_list  *tmp;

    if (ft_lstsize(*a) < 2)
        return (0);
    tmp = (*a);
    (*a) = (*a) -> next;
    tmp -> next = (*a) -> next;
    (*a) -> next = tmp;
    if (s)
        ft_printf("%s\n", s);
    return (1);
}