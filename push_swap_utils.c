/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:20:35 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/15 17:03:08 by vaghazar         ###   ########.fr       */
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

int	**create_chunk(t_list *stack)
{
	int		stack_size;
	int		range_chunk;
	int		**tab;
	int		start_chunk;
	int		i;
	int		divide;
	
	if (!stack)
		return (0);
	ft_printf("create_chunk\n");
	stack_size = ft_lstsize(stack);
	divide = stack_size * 5 / 100;
	divide = 5;
	range_chunk = stack_size / divide;
	tab = malloc(sizeof(int *) * (divide + 1));
	start_chunk = 0;
	i = 0;
	// ft_printf("stack_size = %d\n", stack_size);
	while (i < divide)
		tab[i++] = (int *)malloc(sizeof(int) * 2);
	tab[i] = NULL;
	i = 0;
	while (tab[i + 1] != NULL)
	{
		tab[i][0] = start_chunk;
		tab[i][1] = start_chunk + range_chunk;
		start_chunk = start_chunk + range_chunk;
		i++;
	}
	tab[i][1] = stack_size - 3;;
	tab[i][0] = start_chunk;
	ft_printf("barev\n");
	int j = 0;
	i = -1;
	while (tab[++i])
	{
		j = 0; 
		while (j < 2)
			printf("tab = %d\n", tab[i][j++]);
		// printf("i = %d\n", i);
	}
	ft_printf("create_chunk\n");
	return (tab);
}

void	set_index(t_list **stack)
{
	t_list	*min_num;
	t_list	*start_lst;
	int		i;
	int		stack_size;
	int		bool;
	// ft_printf("set_index\n");
	start_lst = *stack;
	while (*stack)
	{
		(*stack)->index = -1;
		*stack = (*stack)->next;
	}
	*stack = start_lst;
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
			if ((bool && (*stack) -> index == -1)
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
	// ft_printf("set_index\n");
}

var get_targets(t_list	*stack, int	**tab, int i)
{
	t_list	*start_stack;
	var		target;
	// ft_printf("get_targets\n");
	// ft_printf("test targets.target[0] =%p\n", target.target[0]);
	// ft_printf("test targets.target[1] =%p\n", target.target[1]);
	start_stack = stack;
	// ft_printf("stack = %d\n", stack->next->index);
	while (stack -> next)
	{
		// ft_printf("tab[i]= %p , %p \n", &tab[i][0], &tab[i][1]);
		// ft_printf("barev\n");
		// ft_printf("test targets.target[0] =%p\n", target.target[0]);
		// ft_printf("test targets.target[1] =%p\n", target.target[1]);
		// ft_printf("stack = %d\n", stack->index);
		if (stack->index >= tab[i][0] && stack->index <= tab[i][1])
			break;
	// ft_printf("barev\n");
		stack = stack->next;
	}
	target.target[0] = stack;
	stack = start_stack;
	target.target[1] = stack;
	while (stack -> next)
	{
		if(stack->index >= tab[i][0] && stack->index <= tab[i][1])
			target.target[1] = stack;
		stack = stack->next;
	}
	stack = start_stack;
	// ft_printf("get_targets\n");
	return(target);
}

int	get_index_for_push(t_list *stack, int **tab, int count)
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
	return (targets.target[i]->index);
}