/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:26:21 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/05 19:48:46 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	sort_stack_up(t_list	**stack)
{
	int	count_step;
	t_list	*start_lst;

	count_step = 0;
	if (!(*stack))
		return (0);
	if ((*stack) -> data > ((*stack) -> next) -> data)
		count_step += swap_a(stack);
	return (count_step);
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

int	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int		stack_size;
	t_list	*min_num;
	int		i;
	t_list	*start_lst;
	int		count_step;
	int		min_size;
	
	i = 0;
	count_step = 0;
	stack_size = ft_lstsize(*stack_a);
	while (*stack_a)
	{
		start_lst = *stack_a;
		stack_size = ft_lstsize(*stack_a);
		min_num = *stack_a;
		while ((*stack_a))
		{
			if ((*stack_a) -> data < min_num -> data)
				min_num = *stack_a;
			*stack_a = (*stack_a) -> next;
		}
		min_size = ft_lstsize(min_num);
		*stack_a = start_lst;
		if (min_size > stack_size / 2)
			while (*stack_a && (*stack_a) -> data != min_num -> data)
				count_step += rotate_stack(stack_a);
		else
			while (*stack_a && (*stack_a) -> data != min_num -> data)
				count_step += reverse_rotate_stack(stack_a);
		if (stack_size == 2)
			sort_stack_up(stack_a);
		ft_print_list(*stack_a);
		if (is_growth_sequence(*stack_a)) 
			break;
		count_step += push_first_sec(stack_a, stack_b);
		stack_size -= 1;
	}
	while (*stack_b)
		count_step += push_first_sec(stack_b, stack_a);
	return (count_step);
}


int main(int ac, char **av)
{
	t_list  *start_a;
	int steps;
	t_list *stack_a;
	t_list *stack_b;
	int i;
	(void)av;
	(void)ac; 
	char ptr[100][10] = {"46", "44" ,"68" ,"40" ,"66" ,"93" ,"91" ,"56" ,"45" ,"19" ,"65" ,
		"76" ,"73" ,"33" ,"81" ,"80" ,"92" ,"9" ,"10" ,"63"};

	// if (ac < 2)
	// 	return (0);
	stack_b = NULL;
	steps = 0;
	i = 0;
	stack_a = ft_lstnew(ft_atoi(ptr[i++]));
	start_a = stack_a;
	stack_a -> index = -1;
	while (20 > i)
	{
		stack_a -> next = ft_lstnew(ft_atoi(ptr[i++]));
		stack_a -> next -> index = -1;
		stack_a = stack_a -> next;
	}
	stack_a = NULL;
	printf("stack_a\n");
	ft_print_list(start_a);
	set_index(&start_a);
	// printf("index = %d\n", start_a -> index);
	// printf("index = %d\n", start_a -> next ->  index);
	steps += sort_stack(&start_a, &stack_b);
	// steps += sort_stack_up(&start_a);
	printf("stack_a\n");
	ft_print_list(start_a);
	printf("steps = %d\n", steps);
}