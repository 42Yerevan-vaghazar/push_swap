/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:53:49 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/23 13:37:44 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_list **stack)
{
	t_var	vars;

	vars.start_lst = *stack;
	*stack = vars.start_lst;
	vars.i = 0;
	vars.stack_size = ft_lstsize(*stack);
	while (vars.i < vars.stack_size)
	{
		vars.flag = 1;
		*stack = vars.start_lst;
		vars.min_num_a = *stack;
		while (*stack)
		{
			if (((vars.flag && (*stack)->index == -1))
				|| (((vars.min_num_a->data > (*stack)->data)
						&& (*stack)->index == -1)))
			{
				vars.min_num_a = *stack;
				vars.flag = 0;
			}
			*stack = (*stack)->next;
		}
		vars.min_num_a -> index = vars.i++;
	}
	*stack = vars.start_lst;
}
