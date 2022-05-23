/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:20:35 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/23 13:28:21 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_growth_sequence(t_list	*stack)
{
	if (!stack || !(stack -> next))
		return (0);
	while (stack -> next)
	{
		if (stack -> data > (stack->next)->data)
			return (0);
		stack = stack -> next;
	}
	return (1);
}

void	sort_stack_up(t_list	**stack)
{
	if (!(*stack))
		return ;
	if ((*stack)->data > ((*stack)->next)->data)
		swap(stack, "sa");
}

t_list	*get_index_for_push(t_list *stack, int **tab, int count)
{
	int		min_step_num;
	int		i;
	t_var	targets;

	targets = get_targets(stack, tab, count);
	targets.stack_size = ft_lstsize(stack);
	targets.nums[0] = targets.stack_size - ft_lstsize(targets.target[0]);
	targets.nums[1] = ft_lstsize(targets.target[1]);
	min_step_num = targets.nums[0];
	i = -1;
	while (++i < 2)
		if (min_step_num > targets.nums[i])
			min_step_num = targets.nums[i];
	i = 0;
	while (targets.nums[i] != min_step_num)
		i++;
	return (targets.target[i]);
}

t_list	*stack_max_num(t_list *stack)
{
	t_list	*max_num;

	max_num = stack;
	while (stack)
	{
		if (stack->index > max_num->index)
			max_num = stack;
		stack = stack->next;
	}
	return (max_num);
}

t_list	*stack_min_num(t_list *stack)
{
	t_list	*min_num;

	min_num = stack;
	while (stack)
	{
		if (stack->index < min_num->index)
			min_num = stack;
		stack = stack->next;
	}
	return (min_num);
}
