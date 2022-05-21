/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:26:21 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/21 13:01:31 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

var get_targets(t_list	*stack, int	**tab, int i)
{
	t_list	*start_stack;
	var		target;
	// ft_printf("get_targets\n");
	start_stack = stack;
	while (stack -> next)
	{
		if (stack->index >= tab[i][0] && stack->index <= tab[i][1])
			break;
		stack = stack->next;
	}
	target.target[0] = stack;
	stack = start_stack;
	target.target[1] = stack;
	while (stack)
	{
		if(stack->index >= tab[i][0] && stack->index <= tab[i][1])
			target.target[1] = stack;
		stack = stack->next;
	}
	stack = start_stack;
	// ft_printf("get_targets\n");
	return(target);
}

int	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int		count_step = 0;
	int		stack_size_a;
	int		stack_size_b;
	t_list	*min_num_a;
	t_list	*min_num_b;
	int		i;
	t_list	*start_lst;
	int		min_size_a;
	int		max_size;
	int		min_size_b;
	int		count;
	int		flag;
	
	// ft_printf("sort_stack\n");
	i = 0;
	count = 0;
	flag = 1;
	int	**tab = create_chunk(*stack_a);
	stack_size_a = ft_lstsize(*stack_a);
	max_size = stack_size_a - 1;
	while (1)
	{
		flag = 1;
		start_lst = *stack_a;
		if (count > tab[i][1])
			i++;
		stack_size_b = ft_lstsize(*stack_b);
		stack_size_a = ft_lstsize(*stack_a);
		min_num_a = get_index_for_push(*stack_a, tab, i);
		// ft_printf("index = %d\n", min_num_a->index);
		min_num_b = get_target_for_b(*stack_b, min_num_a, &flag);
		min_size_a = ft_lstsize(min_num_a);
		min_size_b = ft_lstsize(min_num_b);
		// ft_printf("index b = %d\n", min_num_b->index);
		// ft_printf("index a = %d\n", min_num_a->index);
		while (min_size_b >= stack_size_b / 2 && min_size_a >= stack_size_a / 2
			&& *stack_a && (*stack_a) -> index != min_num_a -> index
			&& *stack_b && (*stack_b)->index != min_num_b->index)
			count_step += rr(stack_a, stack_b);
		while (min_size_b >= stack_size_b / 2 && *stack_b && (*stack_b) -> index != min_num_b -> index)
			count_step += rotate_stack(stack_b, "rb");
		while (min_size_a >= stack_size_a / 2 && *stack_a && (*stack_a) -> index != min_num_a -> index)
		{
			count_step += rotate_stack(stack_a, "ra");
		}
		while (min_size_a <= stack_size_a / 2 && min_size_b <= stack_size_b / 2 
		&& *stack_b && (*stack_b) -> index != min_num_b -> index 
			&& *stack_a && (*stack_a) -> index != min_num_a -> index)
			count_step += rrr(stack_a, stack_b);
		while (min_size_b <= stack_size_b / 2 && *stack_b && (*stack_b) -> index != min_num_b -> index)
		{
			count_step += reverse_rotate_stack(stack_b, "rrb");
		}
		while (min_size_a <= stack_size_a / 2 && *stack_a && (*stack_a) -> index != min_num_a -> index)
		{
			count_step += reverse_rotate_stack(stack_a, "rra");
		}
		count_step += push_first_sec(stack_a, stack_b, "pb");
		if (!flag)
		{
			count_step += rotate_stack(stack_b, "rb");
		}
		stack_size_a -= 1;
		stack_size_b += 1;
		count++;
		// ft_printf("stack_size = %d\n", stack_size);
		if (stack_size_b == 2 && (*stack_b)->index < (*stack_b)->next->index)
			count_step += swap_b(stack_b);
		// printf("stack_b\n");
		// ft_print_list(*stack_b);
		// printf("stack_a\n");
		// ft_print_list(*stack_a);
		if (stack_size_a == 2)
		{
			// ft_printf("check\n");
			count_step += sort_stack_up(stack_a);
			break;
		}
			// printf("stack_a\n");
			// ft_print_list(*stack_a);
	}
	// ft_printf("count_step = %d\n", count_step);
	// printf("stack_b\n");
	// ft_print_list(*stack_b);
	while (*stack_b)
	{
		
		sort_stack_a_by_index(stack_a, stack_b, i++, &count_step);
	}
	// ft_printf("sort_stack\n");
	// free_tab(tab);
	return (count_step);
}



t_list	*get_target_for_b(t_list *stack, t_list	*target, int *flag)
{
	t_list	*near_num;
	int		b;
	int		a;
	// t_list	*max_num;
	// t_list	*min_num;
	// ft_printf("stack_b");
	// ft_print_list(stack);
	near_num = stack;
	if (stack && stack_max_num(stack)->index < target->index)
	{
		// ft_printf("stack_max_num\n");
		return (stack_max_num(stack));
	}
	if (stack && stack_min_num(stack)->index > target->index)
	{
		if (ft_lstsize(stack) > 2)
		*flag = 0;
		// ft_printf("stack_min_num\n");
		return (stack_max_num(stack));
	}
	while (stack && target->index < stack->index)
	{
		stack = stack->next;
	}
	near_num = stack;
	while (stack)
	{
		a = target->index - stack->index;
		b = target->index - near_num->index;
		if ((target->index > stack->index && target->index - stack->index < target->index - near_num->index))
			near_num = stack;
		stack = stack -> next;
	}
	// if (near_num && target)
	// {
	// 	ft_printf("target->index b = %d\n", target->index);
	// 	ft_printf("near_num = %d\n", near_num->index);
	// }
	return (near_num);
}

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
	
	i = -1;
	while (str[++i])
		if(!ft_isdigit((int)str[i]) && str[i] != '-' && str[i] != '+')
		{
			ft_printf("Error: not a number\n");
			return (0);
		}
	return (1);
}

int	free_array(char	**s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		free(s[i]);
	}
	
	free(s);
	return (1);
}

int	free_tab(int **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
	{
		free(tab[i]);
	}
	free(tab);
	return (1);
}

t_list	*fill_list(int ac, char	**str)
{
	t_list *stack_a;
	t_list  *start_a;
	char	**args;
	int 	i;
	int		j;
	
	i = 1;
	j = 0;
	args = ft_split(str[i], ' ');
	if (!check_is_num(args[j]) && free_array(args))
		return (NULL);
	stack_a = ft_lstnew(ft_atoi(args[j++]));
	start_a = stack_a;
	stack_a -> index = -1;
	while (i++ < ac)
	{
		while (args[j])
		{
			if (!check_is_num(args[j]) && free_array(args))
				return (NULL);
			stack_a -> next = ft_lstnew(ft_atoi(args[j]));
			stack_a -> next -> index = -1;
			stack_a = stack_a -> next;
			free(args[j++]);
		}
		if (i < ac)
			args = ft_split(str[i], ' ');
		j = 0;
	}
	free(args);
	stack_a = NULL;
	set_index(&start_a);
	if (!check_is_circulate(start_a) && ft_lstclear(&start_a))
		return (0);
	return (start_a);
}

int main(int ac, char **av)
{
	int steps;
	t_list *stack_a;
	t_list *stack_b;
	int 	i;
	
	if (ac < 2)
		return (0);
	stack_b = NULL;
	steps = 0;
	i = 0;
	stack_a = fill_list(ac, av);
	if (stack_a == NULL)
		exit (1);
	// ft_printf("stack_a\n");
	// ft_print_list(start_a);
	
	steps += sort_stack(&stack_a, &stack_b);
	// printf("stack_a\n");
	// ft_print_list(stack_a);
	// ft_printf("steps = %d\n", steps);

	
	return (0);
}