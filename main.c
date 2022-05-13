/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:26:21 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/13 19:41:31 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	count_step = 0;
	int		stack_size;
	t_list	*min_num;
	int		i;
	t_list	*start_lst;
	int		min_size;
	int		index;
	int		max_size;
	int		count;
	
	i = 0;
	count = 0;
	int	**tab = create_chunk(*stack_a);
	stack_size = ft_lstsize(*stack_a);
	max_size = stack_size - 1;
	while (1)
	{
		start_lst = *stack_a;
		// ft_printf("check\n");
		if (count > tab[i][1])
			i++;
		index = get_index_for_push(*stack_a, tab, i);
		stack_size = ft_lstsize(*stack_a);
		while ((*stack_a))
		{
			if ((*stack_a) -> index == index)
			{
				min_num = *stack_a;
				break ;
			}
			*stack_a = (*stack_a) -> next;
		}
		min_size = ft_lstsize(min_num);
		ft_printf("index = %d\n", min_num->index);
		*stack_a = start_lst;
		if (min_size > stack_size / 2)
		{
			ft_printf("barev\n");
			while (*stack_a && (*stack_a) -> index != min_num -> index && (*stack_a)->index > min_num->index)
			{
					ft_printf("stack_a\n");
					ft_print_list(*stack_a);
					ft_printf("stack_b\n");
					ft_print_list(*stack_b);
					count_step += rr(stack_a, stack_b);
			}
			while (*stack_a && (*stack_a) -> index != min_num -> index)	
			{
					ft_printf("stack_a\n");
					ft_print_list(*stack_a);
					ft_printf("stack_b\n");
					ft_print_list(*stack_b);
				count_step += rotate_stack(stack_a, "ra");
			}
		}
		else
		{	
			while (*stack_a && (*stack_a) -> index != min_num -> index && (*stack_a)->index < min_num->index)
					ft_printf("stack_a\n");
					ft_print_list(*stack_a);
					ft_printf("stack_b\n");
					ft_print_list(*stack_b);
				count_step += rrr(stack_a, stack_b);
			while (*stack_a && (*stack_a) -> index != min_num -> index)
			{
					ft_printf("stack_a\n");
					ft_print_list(*stack_a);
					ft_printf("stack_b\n");
					ft_print_list(*stack_b);
				count_step += reverse_rotate_stack(stack_a, "rra");
			}
		}
		if (stack_size == 2)
			sort_stack_up(stack_a);
		if (is_growth_sequence(*stack_a)) 
			break;
		count_step += push_first_sec(stack_a, stack_b);
		count++;
		stack_size -= 1;
	}
		// printf("stack_a\n");
		// ft_print_list(*stack_a);
		// printf("stack_b\n");
		// ft_print_list(*stack_b);
	i = 0;
	ft_printf("count_step = %d\n", count_step);
	while (*stack_b)
		sort_stack_a_by_index(stack_a, stack_b, i++, &count_step);
		// printf("stack_a\n");
		// ft_print_list(*stack_a);
		// printf("stack_b\n");
		// ft_print_list(*stack_b);
	
	return (count_step);
}

int	get_index_for_push(t_list *stack, int **tab, int count)
{
	int	min_step_num;
	int	i;
	var	targets;
	
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
	return (targets.target[i]->index);
}

int	**create_chunk(t_list *stack)
{
	int		stack_size;
	int		range_chunk;
	int		**tab;
	int		start_chunk;
	int		i;
	
	stack_size = ft_lstsize(stack);
	range_chunk = stack_size / 5;
	tab = malloc(sizeof(int) * 6);
	start_chunk = 0;
	i = -1;
	while (++i < 5)
		tab[i] = malloc(sizeof(int) * 2);
	tab[i] = NULL;
	i = -1;
	while (tab[++i + 1] != NULL)
	{
		tab[i][0] = start_chunk;
		tab[i][1] = start_chunk + range_chunk;
		start_chunk = start_chunk + range_chunk;
	}
	tab[i][0] = start_chunk;
	tab[i][1] = stack_size - 3;;
	// int j = 0;
	// i = -1;
	// while (tab[++i])
	// {
	// 	j = 0; 
	// 	while (j < 2)
	// 		printf("tab = %d\n", tab[i][j++]);
	// 	// printf("i = %d\n", i);
	// }
	return (tab);
}


var get_targets(t_list	*stack, int	**tab, int i)
{
	t_list	*start_stack;
	var		target;

	start_stack = stack;
	while (stack)
	{
		if (stack->index >= tab[i][0] && stack->index <= tab[i][1])
			break;
		stack = stack->next;
	}
	target.target[0] = stack;
	stack = start_stack;
	while (stack)
	{
		if(stack->index >= tab[i][0] && stack->index <= tab[i][1])
			target.target[1] = stack;
		stack = stack->next;
	}
	stack = start_stack;
	return(target);
}

int main(int ac, char **av)
{
	t_list  *start_a;
	int steps;
	t_list *stack_a;
	t_list *stack_b;
	int 	i;
	
	if (ac < 2)
		return (0);
	stack_b = NULL;
	steps = 0;
	i = 1;
	stack_a = ft_lstnew(ft_atoi(av[i++]));
	start_a = stack_a;
	stack_a -> index = -1;
	while (ac > i)
	{
		stack_a -> next = ft_lstnew(ft_atoi(av[i++]));
		stack_a -> next -> index = -1;
		stack_a = stack_a -> next;
	}
	stack_a = NULL;
	// printf("stack_a\n");
	// ft_print_list(start_a);
	set_index(&start_a);
	// printf("stack_a\n");
	// ft_print_list(start_a);
	
	steps += sort_stack(&start_a, &stack_b);
	// printf("stack_a\n");
	// ft_print_list(start_a);
	printf("steps = %d\n", steps);
}