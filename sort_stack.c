/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:58:26 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/22 14:43:20 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// void	sort_with_rotate(var vars, t_stacks stacks)
// {
// 	while (vars.min_size_b >= vars.stack_size_b / 2 && vars.min_size_a >= vars.stack_size_a / 2
// 		&& *stack_a && (*stack_a) -> index != vars.min_num_a -> index
// 		&& *stack_b && (*stack_b)->index != vars.min_num_b->index)
// 		count_step += rr(stack_a, stack_b);
// 	while (vars.min_size_b >= vars.stack_size_b / 2 && *stack_b && (*stack_b) -> index != vars.min_num_b -> index)
// 		count_step += rotate_stack(stack_b, "rb");
// 	while (min_size_a >= stack_size_a / 2 && *stack_a && (*stack_a) -> index != min_num_a -> index)
// 	{
// 		count_step += rotate_stack(stack_a, "ra");
// 	}
// }

// int	sort_stack(t_list **stack_a, t_list **stack_b)
// {
// 	int		count_step = 0;
// 	var		vars;
	
// 	// ft_printf("sort_stack\n");
// 	vars.i = 0;
// 	vars.count = 0;
// 	vars.flag = 1;
// 	vars.tab = create_chunk(*stack_a, 5);
// 	vars.stack_size_a = ft_lstsize(*stack_a);
// 	vars.max_size = vars.stack_size_a - 1;
// 	while (1)
// 	{
// 		vars.flag = 1;
// 		vars.start_lst = *stack_a;
// 		if (vars.count > vars.tab[vars.i][1])
// 			vars.i++;
// 		vars.stack_size_b = ft_lstsize(*stack_b);
// 		vars.stack_size_a = ft_lstsize(*stack_a);
// 		vars.min_num_a = get_index_for_push(*stack_a, vars.tab, vars.i);
// 		vars.min_num_b = get_target_for_b(*stack_b, vars.min_num_a, &(vars.flag));
// 		vars.min_size_a = ft_lstsize(vars.min_num_a);
// 		vars.min_size_b = ft_lstsize(vars.min_num_b);
// 		while (vars.min_size_b >= vars.stack_size_b / 2 && vars.min_size_a >= vars.stack_size_a / 2
// 			&& *stack_a && (*stack_a) -> index != vars.min_num_a -> index
// 			&& *stack_b && (*stack_b)->index != vars.min_num_b->index)
// 			count_step += rr(stack_a, stack_b);
// 		while (vars.min_size_b >= vars.stack_size_b / 2 && *stack_b && (*stack_b) -> index != vars.min_num_b -> index)
// 			count_step += rotate_stack(stack_b, "rb");
// 		while (vars.min_size_a >= vars.stack_size_a / 2 && *stack_a && (*stack_a) -> index != vars.min_num_a -> index)
// 		{
// 			count_step += rotate_stack(stack_a, "ra");
// 		}
// 		while (vars.min_size_a <= vars.stack_size_a / 2 && vars.min_size_b <= vars.stack_size_b / 2 
// 		&& *stack_b && (*stack_b) -> index != vars.min_num_b -> index 
// 			&& *stack_a && (*stack_a) -> index != vars.min_num_a -> index)
// 			count_step += rrr(stack_a, stack_b);
// 		while (vars.min_size_b <= vars.stack_size_b / 2 && *stack_b && (*stack_b) -> index != vars.min_num_b -> index)
// 		{
// 			count_step += reverse_rotate_stack(stack_b, "rrb");
// 		}
// 		while (vars.min_size_a <= vars.stack_size_a / 2 && *stack_a && (*stack_a) -> index != vars.min_num_a -> index)
// 		{
// 			count_step += reverse_rotate_stack(stack_a, "rra");
// 		}
// 		count_step += push_first_sec(stack_a, stack_b, "pb");
// 		if (!vars.flag)
// 		{
// 			count_step += rotate_stack(stack_b, "rb");
// 		}
// 		vars.stack_size_a -= 1;
// 		vars.stack_size_b += 1;
// 		vars.count++;
// 		// ft_printf("stack_size = %d\n", stack_size);
// 		if (vars.stack_size_b == 2 && (*stack_b)->index < (*stack_b)->next->index)
// 			count_step += swap_b(stack_b);
// 		if (vars.stack_size_a == 2)
// 		{
// 			count_step += sort_stack_up(stack_a);
// 			break;
// 		}
// 			// printf("stack_a\n");
// 			// ft_print_list(*stack_a);
// 	}
// 	// ft_printf("count_step = %d\n", count_step);
// 	// printf("stack_b\n");
// 	// ft_print_list(*stack_b);
// 	while (*stack_b)
// 	{
		
// 		sort_stack_a_by_index(stack_a, stack_b, vars.i++, &count_step);
// 	}
// 	// ft_printf("sort_stack\n");
// 	// free_vars.tab(vars.tab);
// 	return (count_step);
// }