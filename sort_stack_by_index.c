/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b_by_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:09:03 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/13 18:40:48 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sort_stack_a_by_index(t_list **stack_a,t_list **stack_b, int index, int *count_step)
{
    int stack_b_size;
    t_list  *max_num;
    t_list  *start_lst;
    int min_size;
    (void)index;

    start_lst = *stack_b;
    stack_b_size = ft_lstsize(*stack_b);
    max_num = *stack_b;
	while ((*stack_b))
	{
		if ((*stack_b)->data > max_num->data)
			max_num = *stack_b;
		*stack_b = (*stack_b) -> next;
	}
	// min_num = get_target_for_b(*stack_a, (*stack_b), 0);
	min_size = ft_lstsize(max_num);
	*stack_b = start_lst;
	if (min_size > stack_b_size / 2)
		while (*stack_b && (*stack_b) -> index != max_num -> index)	
			*count_step += rotate_stack(stack_b, "rb");
	else
		while (*stack_b && (*stack_b) -> index != max_num -> index)
			*count_step += reverse_rotate_stack(stack_b, "rrb");
    *count_step += push_first_sec(stack_b, stack_a, "pa");
    return (*count_step);
}