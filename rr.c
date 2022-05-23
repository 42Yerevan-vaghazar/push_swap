/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:53:21 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/23 13:18:04 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rr(t_list **stack_a, t_list **stack_b, char *s)
{
	rotate_stack(stack_a, s);
	rotate_stack(stack_b, NULL);
	return (1);
}

int	rrr(t_list **stack_a, t_list **stack_b, char *s)
{
	reverse_rotate_stack(stack_a, s);
	reverse_rotate_stack(stack_b, NULL);
	return (1);
}
