/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:03:31 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/23 13:54:21 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initilizer(t_var *vars)
{
	vars->i = 0;
	vars->j = 0;
	vars->flag = 0;
}

static void	helper(t_var *vars, t_list **stack_a, char **args, t_list **start_a)
{
	if (!vars->flag++)
	{	
		(*stack_a) = ft_lstnew(ft_atoi(args[vars->j++]));
		*start_a = (*stack_a);
	}
	else
	{
		(*stack_a)->next = ft_lstnew(ft_atoi(args[vars->j++]));
		(*stack_a) = (*stack_a)->next;
	}
}

static int	fill_list_helper(t_list **stack_a, char **args, int ac, char **str)
{
	t_list	*start_a;
	t_var	vars;

	initilizer(&vars);
	while (++vars.i < ac)
	{
		args = ft_split(str[vars.i], ' ');
		while (args[vars.j] || !free_array(args))
		{
			if ((!check_is_num(args[vars.j])
					|| !is_integer_num(ft_atoi(args[vars.j])))
				&& free_array(args))
				return (0);
			helper(&vars, stack_a, args, &start_a);
		}
		vars.j = 0;
	}
	(*stack_a) = NULL;
	(*stack_a) = start_a;
	return (1);
}

t_list	*fill_list(int ac, char	**str)
{
	t_list	*stack_a;
	char	**args;

	args = NULL;
	if (!fill_list_helper(&stack_a, args, ac, str) && free_lst(&stack_a))
		return (0);
	set_index(&stack_a);
	if (!check_is_circulate(stack_a) && free_lst(&stack_a))
		return (0);
	return (stack_a);
}
