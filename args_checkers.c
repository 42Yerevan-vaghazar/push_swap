/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 12:11:55 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/22 14:42:49 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_circulate(t_list *stack)
{
	t_list	*next_node;
	
	while (stack -> next)
	{
		next_node = stack -> next;
		while (next_node)
		{
			if (stack->data == next_node->data)
			{
				ft_printf("Error: duplicated number\n");
				return (0);
			}
			next_node = next_node->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	check_is_num(char *str)
{
	int	i;
	
	i = 0;
	if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[i + 1]))
	{
		ft_printf("Error: not a number\n");
		return (0);
	}
	while (str[i])
	{	
		if(!ft_isdigit((int)str[i]) && str[0] != '-' && str[0] != '+')
		{
			ft_printf("Error: not a number\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_integer_num(long long num)
{
	if (num <  MIN_INT ||  num > MAX_INT)
	{
		ft_printf("Error: out of range");
		return (0);
	}
	return (1);
}