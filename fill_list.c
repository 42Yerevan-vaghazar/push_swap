/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:03:31 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/22 15:41:59 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int fill_list_helper(t_list **stack_a, char  **args, int ac, char **str)
{
	t_list  *start_a;
	int 	i;
	int		j;
	
	i = 1;
	j = 0;
	(*stack_a) = ft_lstnew(ft_atoi(args[j++]));
	start_a = (*stack_a);
	(*stack_a) -> index = -1;
	while (i++ < ac)
	{
		while (args[j])
		{
			if ((!check_is_num(args[j]) || !is_integer_num(ft_atoi(args[j])))/* && free_array(args)*/)
				return (0);
			(*stack_a) -> next = ft_lstnew(ft_atoi(args[j]));
			(*stack_a) -> next -> index = -1;
			(*stack_a) = (*stack_a) -> next;
			free(args[j++]);
		}
		if (i < ac)
			args = ft_split(str[i], ' ');
		j = 0;
	}
	(*stack_a) = NULL;
	(*stack_a) = start_a;
	return (1);
}

t_list	*fill_list(int ac, char	**str)
{
	t_list  *stack_a;
	char	**args;
	
	args = ft_split(str[1], ' ');
	if (!check_is_num(args[0]) && free_array(args))
		return (NULL);
	if (!fill_list_helper(&stack_a, args, ac,  str))
		return (0);
	free(args);
	set_index(&stack_a);
	if (!check_is_circulate(stack_a) /*&& ft_lstclear(&start_a)*/)
		return (0);
	return (stack_a);
}