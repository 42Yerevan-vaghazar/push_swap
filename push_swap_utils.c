/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:20:35 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/21 20:17:04 by vaghazar         ###   ########.fr       */
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
		ft_printf("|i = %d # ", lst -> index);
		ft_printf("%d |", lst -> data);
		lst = lst -> next;
	}
	ft_printf("\n-----------------\n");
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

int	**create_chunk(t_list *stack, int divide)
{
	int		stack_size;
	int		range_chunk;
	int		**tab;
	int		start_chunk;
	int		i;
	
	if (!stack)
		return (0);
	// ft_printf("create_chunk\n");
	stack_size = ft_lstsize(stack);
	range_chunk = stack_size / divide;
	tab = malloc(sizeof(int *) * (divide + 1));
	start_chunk = 0;
	i = 0;
	// ft_printf("stack_size = %d\n", stack_size);
	while (i < divide)
		tab[i++] = (int *)malloc(sizeof(int) * 2);
	tab[i] = NULL;
	i = 0;
	while (tab[i + 1] != NULL && ((start_chunk + range_chunk) < stack_size - 3))
	{
		tab[i][0] = start_chunk;
		tab[i][1] = start_chunk + range_chunk;
		start_chunk = start_chunk + range_chunk;
		i++;
	}
	tab[i][1] = stack_size - 3;;
	tab[i][0] = start_chunk;
	// int j = 0;
	// i = -1;
	// while (tab[++i])
	// {
	// 	j = 0; 
	// 	while (j < 2)
	// 		printf("tab = %d\n", tab[i][j++]);
	// 	// printf("i = %d\n", i);
	// }
	// ft_printf("create_chunk\n");
	return (tab);
}

void	set_index(t_list **stack)
{
	t_list	*min_num;
	t_list	*start_lst;
	int		i;
	int		stack_size;
	int		boolean;
	start_lst = *stack;
	while (*stack)
	{
		(*stack)->index = -1;
		*stack = (*stack)->next;
	}
	*stack = start_lst;
	i = 0;
	boolean = 1;
	stack_size = ft_lstsize(*stack);
	while (i < stack_size)
	{
		boolean = 1;
		*stack = start_lst;
		min_num = *stack;
		while (*stack)
		{
			if ((boolean && (*stack) -> index == -1)
				|| ((min_num -> data > (*stack) -> data) && (*stack) -> index == -1))
			{
				min_num = *stack;
				boolean = 0;
			}
			*stack = (*stack) -> next;
		}
		min_num -> index = i++;
	}
	*stack = start_lst;
}

t_list	*get_index_for_push(t_list *stack, int **tab, int count)
{
	int	min_step_num;
	int	i;
	var	targets;
	// ft_printf("get_index_for_push\n");
	// ft_printf("targets.target[0]%p\n", targets.target[0]);
	// ft_printf("targets.target[1]%p\n", targets.target[1]);
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
	// ft_printf("get_index_for_push\n");
	// ft_printf("i =%d\n", i);
	// ft_printf("targets.target[i]%p\n", &targets.target[i]);
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