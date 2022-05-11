/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:26:21 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/11 21:52:29 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int count = 0;


int	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int		stack_size;
	t_list	*min_num;
	int		i;
	t_list	*start_lst;
	int		count_step;
	int		min_size;
	int		index;
	int		max_size;
	
	i = 0;
	count_step = 0;
	stack_size = ft_lstsize(*stack_a);
	max_size = stack_size - 1;
	while (1)
	{
		start_lst = *stack_a;
		index = get_index_for_push(*stack_a);
		printf("%d\n", index);
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
		*stack_a = start_lst;
		if (min_size > stack_size / 2)
			while (*stack_a && (*stack_a) -> index != min_num -> index)
				count_step += rotate_stack(stack_a);
		else
			while (*stack_a && (*stack_a) -> index != min_num -> index)
				count_step += reverse_rotate_stack(stack_a);
		if (stack_size == 2)
			sort_stack_up(stack_a);
		// ft_print_list(*stack_a);
		if (is_growth_sequence(*stack_a)) 
			break;
		count_step += push_first_sec(stack_a, stack_b);
		stack_size -= 1;
		if (index == max_size)
			max_size -= 1;
		else if (index == i)
			i++;
	}
	return (count_step);
}

int	get_index_for_push(t_list *stack)
{
	var	args;
	int	min_step_num;
	int	i;
	var	targets;
	targets = get_targets(stack);	
	// ft_printf("push\n");
	args.stack_size = ft_lstsize(stack);
	args.nums[0] = args.stack_size - ft_lstsize(targets.target[0]);
	args.nums[1] = ft_lstsize(targets.target[1]);
	args.nums[2] = args.stack_size - ft_lstsize(targets.target[2]);
	args.nums[3] = ft_lstsize(targets.target[3]);
	min_step_num = args.nums[0];
	i = -1;
	while (++i < 4)
		if (min_step_num > args.nums[i])
			min_step_num = args.nums[i];	
	i = 0;
	while (args.nums[i] != min_step_num)
		i++;
	return (targets.target[i]->index);
}

int	**create_chunk(t_list *stack)
{
	t_list	*start_stack;
	int		stack_size;
	int		range_chunk;
	int		**tab;
	int		start_chunk;
	int		i;
	
	start_stack = stack;
	stack_size = ft_lstsize(stack);
	range_chunk = stack_size / 5;
	tab = malloc(sizeof(int) * 6);
	start_chunk = 0;
	i = 0;
	while (++i < 5)
		tab[i] = malloc(sizeof(int) * 2);
	ft_printf("i = %d\n", i);
	tab[i] = NULL;
	i = 0;
	while (tab[i])
	{
		if (tab[i] == NULL)
		{
			tab[i][0] = start_chunk;
			tab[i][1] = stack_size;
			break;
		}
		tab[i][0] = start_chunk;
		tab[i][1] = start_chunk + range_chunk;
		start_chunk = start_chunk + range_chunk;
		i++;
	}
	int j = 0;
	i = -1;
	while (tab[++i])
	{
		j = 0; 
		while (j < 2)
			printf("tab = %d\n", tab[i][j++]);
		// printf("i = %d\n", i);
	}
	ft_printf("count = %d\n", count++);
	return (tab);
}


var get_targets(t_list	*stack)
{
	t_list	*start_stack;
	int		**tab;
	var		target;
	int		i;
	int		j;
	start_stack = stack;
	tab = create_chunk(stack);
	i = 0;
	j = 4;
	while (stack)
	{
		// ft_print_list(stack);
		if (stack->index >= tab[i][0] && stack->index <= tab[i][1])
		{
			target.target[0] = stack;
			break;
		}
		stack = stack->next;
	}
	stack = start_stack;
	while (stack)
	{
		if(stack->index >= tab[j][0] && stack->index <= tab[j][1])
		{
			target.target[2] = stack;
			break;
		}
		stack = stack->next;
	}
	stack = start_stack;
	while (stack)
	{
		if(stack->index >= tab[i][0] && stack->index <= tab[i][1])
			target.target[1] = stack;
		if(stack->index >= tab[j][0] && stack->index <= tab[j][1])
			target.target[3] = stack;
		stack = stack->next;
	}
	stack = start_stack;
	// int	a =  get_index_for_push(target, stack);
	// printf("a = %d\n", a);
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