/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:20:30 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/01 10:36:32 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int swap_b(t_list **a)
{
    int tmp;

    if (ft_lstsize(*a) < 2)
        return (0);
    tmp = (*a) -> data;
    (*a) -> data = (*a) -> next -> data;
    (*a) -> next -> data = tmp;
    return (1);
}