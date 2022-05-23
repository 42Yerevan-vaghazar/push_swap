/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 12:10:54 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/23 14:02:53 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_var	get_targets(t_list	*stack, int	**tab, int i)
{
	t_list	*start_stack;
	t_var	target;

	start_stack = stack;
	while (stack -> next)
	{
		if (stack->index >= tab[i][0] && stack->index <= tab[i][1])
			break ;
		stack = stack->next;
	}
	target.target[0] = stack;
	stack = start_stack;
	target.target[1] = stack;
	while (stack)
	{
		if (stack->index >= tab[i][0] && stack->index <= tab[i][1])
			target.target[1] = stack;
		stack = stack->next;
	}
	stack = start_stack;
	return (target);
}

t_list	*get_target_for_b(t_list *stack, t_list	*target, int *flag)
{
	t_list	*near_num;

	near_num = stack;
	if (stack && stack_max_num(stack)->index < target->index)
		return (stack_max_num(stack));
	if (stack && stack_min_num(stack)->index > target->index)
	{
		if (ft_lstsize(stack) > 2)
			*flag = 0;
		return (stack_max_num(stack));
	}
	while (stack && target->index < stack->index)
		stack = stack->next;
	near_num = stack;
	while (stack)
	{
		if ((target->index > stack->index
				&& target->index - stack->index
				< target->index - near_num->index))
			near_num = stack;
		stack = stack -> next;
	}
	return (near_num);
}
