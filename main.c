/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:26:21 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/22 15:43:23 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	correct_stacks(var *vars, t_list **stack_a, t_list	**stack_b)
{
	while (vars->min_size_b >= vars->stack_size_b / 2 && vars->min_size_a >= vars->stack_size_a / 2
		&& *stack_a && (*stack_a) -> index != vars->min_num_a -> index
		&& *stack_b && (*stack_b)->index != vars->min_num_b->index)
		rr(stack_a, stack_b, "rr");
	while (vars->min_size_b >= vars->stack_size_b / 2 && *stack_b && (*stack_b) -> index != vars->min_num_b -> index)
		rotate_stack(stack_b, "rb");
	while (vars->min_size_a >= vars->stack_size_a / 2 && *stack_a && (*stack_a) -> index != vars->min_num_a -> index)
		rotate_stack(stack_a, "ra");
	while (vars->min_size_a <= vars->stack_size_a / 2 && vars->min_size_b <= vars->stack_size_b / 2 
		&& *stack_b && (*stack_b) -> index != vars->min_num_b -> index 
		&& *stack_a && (*stack_a) -> index != vars->min_num_a -> index)
		rrr(stack_a, stack_b, "rrr");
	while (vars->min_size_b <= vars->stack_size_b / 2 && *stack_b && (*stack_b) -> index != vars->min_num_b -> index)
		reverse_rotate_stack(stack_b, "rrb");
	while (vars->min_size_a <= vars->stack_size_a / 2 && *stack_a && (*stack_a) -> index != vars->min_num_a -> index)
		reverse_rotate_stack(stack_a, "rra");
}

void	initialize_vars(var *vars, t_list *stack_a, int *range)
{
	// int range;
	
	*range = 5;
	vars->stack_size_a = ft_lstsize(stack_a);
	if (vars->stack_size_a <= 450 && vars->stack_size_a > 200)
		while (vars->stack_size_a / 3 > 0)
		{
			vars->stack_size_a = vars->stack_size_a / 3;
			*range += 1;
		}
	else if (vars->stack_size_a <= 600 && vars->stack_size_a > 450)
		*range = 14;
	else if (vars->stack_size_a >= 600)
		while (vars->stack_size_a / 50 > 0)
		{
			vars->stack_size_a = vars->stack_size_a / 50;
			*range += 1;
		}
	vars->count = 0;
	vars->i = 0;
	vars->flag = 1;
	vars->min_num_a = 0;
	vars->min_num_b = 0;
	// ft_printf("range = %d\n", *range);
	vars->tab = create_chunk(stack_a, 14);
	vars->stack_size_a = ft_lstsize(stack_a);
	vars->max_size = vars->stack_size_a - 1;
}

void	declare_args(var *vars, t_list **stack_a, t_list **stack_b)
{
	vars->flag = 1;
	vars->start_lst = *stack_a;
	if (vars->count > vars->tab[vars->i][1])
		vars->i++;
	vars->stack_size_b = ft_lstsize(*stack_b);
	vars->stack_size_a = ft_lstsize(*stack_a);
	vars->min_num_a = get_index_for_push(*stack_a, vars->tab, vars->i);
	vars->min_num_b = get_target_for_b(*stack_b, vars->min_num_a, &(vars->flag));
	vars->min_size_a = ft_lstsize(vars->min_num_a);
	vars->min_size_b = ft_lstsize(vars->min_num_b);
}

int	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int		count_step = 0;
	var		vars;
	int range;
	
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
		if (vars.stack_size_b == 2 && (*stack_b)->index < (*stack_b)->next->index)
			swap(stack_b, "sb");
	}
	sort_stack_up(stack_a);
	while (*stack_b)
		sort_stack_a_by_index(stack_a, stack_b, vars.i++, &count_step);
	// ft_printf("range = %d\n", range);
	return (count_step);
}

int sort_5(t_list **stack_a, t_list **stack_b)
{
	t_list *min_num;
	int stack_size_a;
	
	while (ft_lstsize(*stack_a) != 3)
	{
		min_num = stack_min_num(*stack_a);
		stack_size_a = ft_lstsize(min_num);
		if (5 / 2 < stack_size_a)
			while ((*stack_a)->index != min_num->index)
				rotate_stack(stack_a, "ra");
		else 
			while ((*stack_a)->index != min_num->index)
				reverse_rotate_stack(stack_a, "rra");
		push_first_sec(stack_a, stack_b, "pb");
	}
	sort_3(stack_a);
	while (*stack_b)	
		push_first_sec(stack_b, stack_a, "pa");
	return (1);
}

int sort_3(t_list **stack)
{
	if (ft_lstsize(*stack) == 2)
		sort_stack_up(stack);
	else if ((*stack)->index > (*stack)->next->index && (*stack)->index < ft_lstlast(*stack)->index)
		swap(stack, "sa");
	else if ((*stack)->index > (*stack)->next->index && (*stack)->index > ft_lstlast(*stack)->index
			&& (*stack)->next->index < ft_lstlast(*stack)->index)
		rotate_stack(stack, "ra");
	else if ((*stack)->index < (*stack)->next->index && (*stack)->next->index > ft_lstlast(*stack)->index
			&& ft_lstlast(*stack)->index < (*stack)->index)
		reverse_rotate_stack(stack, "rra");
	else if ((*stack)->index > (*stack)->next->index && (*stack)->next->index > ft_lstlast(*stack)->index
			&& (*stack)->index > ft_lstlast(*stack)->index)
	{
		swap(stack, "sa");
		reverse_rotate_stack(stack, "rra");
	}
	else if ((*stack)->index < (*stack)->next->index && (*stack)->next->index > ft_lstlast(*stack)->index
			&& (*stack)->index < ft_lstlast(*stack)->index)
	{
		swap(stack, "sa");
		rotate_stack(stack, "ra");
	}
	return (1);
}

int main(int ac, char **av)
{
	int steps;
	t_list *stack_a;
	t_list *stack_b;
	int 	i;
	
	if (ac < 2)
		return (0);
	stack_b = NULL;
	steps = 0;
	i = 0;
	stack_a = fill_list(ac, av);
	// printf("stack_a\n");m
	// ft_print_list(stack_a);
	if (stack_a == NULL)
		exit (1);
	if (is_growth_sequence(stack_a))
		exit (1);
	if (ft_lstsize(stack_a) <= 3)
		sort_3(&stack_a);
	else if (ft_lstsize(stack_a) <= 5)
		sort_5(&stack_a, &stack_b);
	else 
		steps += sort_stack(&stack_a, &stack_b);
	// ft_printf("steps = %d\n", steps);
	// printf("stack_a\n");
	// ft_print_list(stack_a);
	// printf("ra\n");

	
	return (0);
}