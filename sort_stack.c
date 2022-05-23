/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:58:26 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/23 15:02:29 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	correct_stacks(t_var *vars, t_list **stack_a, t_list	**stack_b)
{
	while (vars->min_size_b >= vars->stack_size_b / 2
		&& vars->min_size_a >= vars->stack_size_a / 2
		&& *stack_a && (*stack_a)->index != vars->min_num_a -> index
		&& *stack_b && (*stack_b)->index != vars->min_num_b->index)
		rr(stack_a, stack_b, "rr");
	while (vars->min_size_b >= vars->stack_size_b / 2 && *stack_b
		&& (*stack_b)->index != vars->min_num_b -> index)
		rotate_stack(stack_b, "rb");
	while (vars->min_size_a >= vars->stack_size_a / 2 && *stack_a
		&& (*stack_a)->index != vars->min_num_a -> index)
		rotate_stack(stack_a, "ra");
	while (vars->min_size_a <= vars->stack_size_a / 2
		&& vars->min_size_b <= vars->stack_size_b / 2
		&& *stack_b && (*stack_b)->index != vars->min_num_b -> index
		&& *stack_a && (*stack_a)->index != vars->min_num_a -> index)
		rrr(stack_a, stack_b, "rrr");
	while (vars->min_size_b <= vars->stack_size_b / 2 && *stack_b
		&& (*stack_b)->index != vars->min_num_b -> index)
		reverse_rotate_stack(stack_b, "rrb");
	while (vars->min_size_a <= vars->stack_size_a / 2 && *stack_a
		&& (*stack_a)->index != vars->min_num_a -> index)
		reverse_rotate_stack(stack_a, "rra");
}

static void	initialize_vars(t_var *vars, t_list *stack_a, int *range)
{
	*range = 5;
	vars->stack_size_a = ft_lstsize(stack_a);
	if (vars->stack_size_a <= 400)
			*range = 5;
	else if (vars->stack_size_a >= 400 && vars->stack_size_a < 750)
		*range = 13;
	else if (vars->stack_size_a >= 750)
	{
		while (vars->stack_size_a > 0)
		{
			vars->stack_size_a = vars->stack_size_a - 50;
			*range += 1;
		}
	}
	vars->count = 0;
	vars->i = 0;
	vars->flag = 1;
	vars->min_num_a = 0;
	vars->min_num_b = 0;
	vars->tab = create_chunk(stack_a, *range);
	vars->stack_size_a = ft_lstsize(stack_a);
	vars->max_size = vars->stack_size_a - 1;
}

static void	declare_args(t_var *vars, t_list **stack_a, t_list **stack_b)
{
	vars->flag = 1;
	vars->start_lst = *stack_a;
	if (vars->count > vars->tab[vars->i][1])
		vars->i++;
	vars->stack_size_b = ft_lstsize(*stack_b);
	vars->stack_size_a = ft_lstsize(*stack_a);
	vars->min_num_a = get_index_for_push(*stack_a, vars->tab, vars->i);
	vars->min_num_b = get_target_for_b(*stack_b,
			vars->min_num_a, &(vars->flag));
	vars->min_size_a = ft_lstsize(vars->min_num_a);
	vars->min_size_b = ft_lstsize(vars->min_num_b);
}

int	sort_stack(t_list **stack_a, t_list **stack_b)
{
	t_var	vars;
	int		range;

	initialize_vars(&vars, *stack_a, &range);
	while (vars.stack_size_a != 2)
	{
		declare_args(&vars, stack_a, stack_b);
		correct_stacks(&vars, stack_a, stack_b);
		push_first_sec(stack_a, stack_b, "pb");
		if (!vars.flag)
			rotate_stack(stack_b, "rb");
		vars.stack_size_a -= 1;
		vars.stack_size_b += 1;
		vars.count++;
		if (vars.stack_size_b == 2
			&& (*stack_b)->index < (*stack_b)->next->index)
			swap(stack_b, "sb");
	}
	sort_stack_up(stack_a);
	while (*stack_b)
		sort_stack_a_by_index(stack_a, stack_b);
	free_tab(vars.tab);
	return (1);
}
