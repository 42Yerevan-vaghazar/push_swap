/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:53:21 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/13 19:25:27 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int rr(t_list **stack_a, t_list **stack_b)
{
    rotate_stack(stack_a, "rr");
    rotate_stack(stack_b, "rr");
    return (1);
}

int rrr(t_list **stack_a, t_list **stack_b)
{
    reverse_rotate_stack(stack_a, "rrr");
    reverse_rotate_stack(stack_b, "rrr");
    return (1);
}