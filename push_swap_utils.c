/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:20:35 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/08 17:15:54 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	is_growth_sequence(t_list	*stack)
{
	if (!stack || !(stack -> next))
		return (0);
	while (stack -> next)
	{
		if (stack -> data > (stack -> next) -> data)
			return (0);
		stack = stack -> next;
	}
	return (1);
}

void    ft_print_list(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		printf("i = %d  ", lst -> index);
		printf("%d ,", lst -> data);
		lst = lst -> next;
	}
	printf("\n-----------------\n");
}

void	set_index(t_list **stack)
{
	t_list	*min_num;
	t_list	*start_lst;
	int		i;
	int		stack_size;
	int		bool;

	start_lst = *stack;
	i = 0;
	bool = 1;
	stack_size = ft_lstsize(*stack);
	while (i < stack_size)
	{
		bool = 1;
		*stack = start_lst;
		min_num = *stack;
		while (*stack)
		{
			if ((min_num -> index != -1 && bool && (*stack) -> index == -1)
				|| ((min_num -> data > (*stack) -> data) && (*stack) -> index == -1))
			{
				min_num = *stack;
				bool = 0;
			}
			*stack = (*stack) -> next;
		}
		min_num -> index = i++;
	}
	*stack = start_lst;
}

int	sort_stack_up(t_list	**stack)
{
	int	count_step;
	// t_list	*start_lst;

	count_step = 0;
	if (!(*stack))
		return (0);
	if ((*stack) -> data > ((*stack) -> next) -> data)
		count_step += swap_a(stack);
	return (count_step);
}