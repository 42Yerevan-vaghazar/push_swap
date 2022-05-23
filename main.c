/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:26:21 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/23 13:59:57 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_5(t_list **stack_a, t_list **stack_b)
{
	t_list	*min_num;
	int		stack_size_a;

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

int	sort_3(t_list **stack)
{
	if (ft_lstsize(*stack) == 2)
		sort_stack_up(stack);
	else if ((*stack)->index > (*stack)->next->index
		&& (*stack)->index < ft_lstlast(*stack)->index)
		swap(stack, "sa");
	else if ((*stack)->index > (*stack)->next->index
		&& (*stack)->index > ft_lstlast(*stack)->index
		&& (*stack)->next->index < ft_lstlast(*stack)->index)
		rotate_stack(stack, "ra");
	else if ((*stack)->index < (*stack)->next->index
		&& (*stack)->next->index > ft_lstlast(*stack)->index
		&& ft_lstlast(*stack)->index < (*stack)->index)
		reverse_rotate_stack(stack, "rra");
	else if ((*stack)->index > (*stack)->next->index
		&& (*stack)->next->index > ft_lstlast(*stack)->index
		&& (*stack)->index > ft_lstlast(*stack)->index && swap(stack, "sa"))
		reverse_rotate_stack(stack, "rra");
	else if ((*stack)->index < (*stack)->next->index
		&& (*stack)->next->index > ft_lstlast(*stack)->index
		&& (*stack)->index < ft_lstlast(*stack)->index && swap(stack, "sa"))
		rotate_stack(stack, "ra");
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	// int		i;

	if (ac < 2)
		return (0);
	stack_b = NULL;
	stack_a = fill_list(ac, av);
	if (stack_a == NULL || ft_lstsize(stack_a) == 1)
		exit (1);
	if (is_growth_sequence(stack_a))
		exit (1);
	if (ft_lstsize(stack_a) <= 3)
		sort_3(&stack_a);
	else if (ft_lstsize(stack_a) <= 5)
		sort_5(&stack_a, &stack_b);
	else
		sort_stack(&stack_a, &stack_b);
	// printf("stack_a\n");
	// ft_print_list(stack_a);
	// printf("ra\n");
	// free_lst(&stack_a);
	free_lst(&stack_a);
	
	return (0);
}
