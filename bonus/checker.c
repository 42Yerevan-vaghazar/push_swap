/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 11:24:41 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/23 13:55:08 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	put_instruction(t_list **stack_a, t_list **stack_b, char *instr)
{
	if (!ft_strcmp(instr, "sa\n"))
		swap(stack_a, NULL);
	else if (!ft_strcmp(instr, "sb\n"))
		swap(stack_b, NULL);
	else if (!ft_strcmp(instr, "ss\n") && swap(stack_b, NULL))
		swap(stack_a, NULL);
	else if (!ft_strcmp(instr, "pa\n"))
		push_first_sec(stack_b, stack_a, NULL);
	else if (!ft_strcmp(instr, "pb\n"))
		push_first_sec(stack_a, stack_b, NULL);
	else if (!ft_strcmp(instr, "ra\n"))
		rotate_stack(stack_a, NULL);
	else if (!ft_strcmp(instr, "rb\n"))
		rotate_stack(stack_b, NULL);
	else if (!ft_strcmp(instr, "rr\n"))
		rr(stack_a, stack_b, NULL);
	else if (!ft_strcmp(instr, "rra\n"))
		reverse_rotate_stack(stack_a, NULL);
	else if (!ft_strcmp(instr, "rrb\n"))
		reverse_rotate_stack(stack_b, NULL);
	else if (!ft_strcmp(instr, "rrr\n"))
		rrr(stack_a, stack_b, NULL);
	else if (ft_printf("Error: wrong instruction\n"))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*instruction;
	int		i;

	if (ac < 2)
		return (0);
	stack_b = NULL;
	i = 0;
	stack_a = fill_list(ac, av);
	if (stack_a == NULL || (ft_lstsize(stack_a) == 1 && ft_printf("OK\n")))
		exit (1);
	while (1)
	{
		instruction = get_next_line(0);
		if (!instruction)
			break ;
		if (!put_instruction(&stack_a, &stack_b, instruction))
			exit (0);
	}
	if (is_growth_sequence(stack_a) && stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO");
	return (0);
}
