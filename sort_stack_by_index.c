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
    t_list  *min_num;
    t_list  *start_lst;
    int min_size;
    (void)index;

    start_lst = *stack_b;
    stack_b_size = ft_lstsize(*stack_b);
    min_num = *stack_b;
	while ((*stack_b))
	{
		if ((*stack_b)->data > min_num->data)
			min_num = *stack_b;
		*stack_b = (*stack_b) -> next;
	}
	min_size = ft_lstsize(min_num);
	*stack_b = start_lst;
	if (min_size > stack_b_size / 2)
		while (*stack_b && (*stack_b) -> data != min_num -> data)	
			*count_step += rotate_stack(stack_b, "rb");
	else
		while (*stack_b && (*stack_b) -> data != min_num -> data)
			*count_step += reverse_rotate_stack(stack_b, "rb");
    *count_step += push_first_sec(stack_b, stack_a, 'a');
    return (*count_step);
}