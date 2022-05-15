/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:26:21 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/15 19:15:29 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	sort_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr;
	int		count_step = 0;
	int		stack_size;
	int		stack_size_b;
	t_list	*min_num;
	int		i;
	t_list	*start_lst;
	int		min_size;
	int		index;
	int		max_size;
	int		count;
	int		flag;
	
	// ft_printf("sort_stack\n");
	i = 0;
	count = 0;
	index = 0;
	flag = 1;
	int	**tab = create_chunk(*stack_a);
	stack_size = ft_lstsize(*stack_a);
	max_size = stack_size - 1;
	while (!is_growth_sequence(*stack_a))
	{
		// printf("stack_b\n");
		// ft_print_list(*stack_b);
		start_lst = *stack_a;
		// if (count == 1)
		// {
		// 	set_index(stack_a);
		// 	ft_printf("stack_a\n");
		// 	ft_print_list(*stack_a);
		// 	tab = create_chunk(*stack_a);
		// 	count = 0;
		// }
	// ft_printf("barev\n");
		if (count > tab[i][1])
			i++;
		index = get_index_for_push(*stack_a, tab, i);
		// ft_printf("index = %d\n", index);
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
		{
			// ft_printf("barev\n");
			// while (*stack_b && (*stack_a) -> index != min_num -> index && (*stack_b) -> index > (min_num) -> index 
			// && ft_lstlast(*stack_b)->index < (min_num)-> index)
			// { 
			// 	count_step += rr(stack_a, stack_b);
			// }
			while (*stack_a && (*stack_a) -> index != min_num -> index)	
			{
				count_step += rotate_stack(stack_a, "ra");
			}
		}
		else
		{	
			// while (*stack_b && (*stack_a) -> index != min_num -> index && (*stack_b) -> index > (min_num) -> index 
			// && ft_lstlast(*stack_b)->index < (min_num)-> index)
			// {
			// 	count_step += rrr(stack_a, stack_b);
			// }
			while (*stack_a && (*stack_a) -> index != min_num -> index)
			{
				count_step += reverse_rotate_stack(stack_a, "rra");
			}
		}
		// ft_printf("stack_a\n");
		// ft_print_list(*stack_a);
		if (*stack_b)
		{
			flag = 1;
			start_lst = *stack_b;
			stack_size_b = ft_lstsize(*stack_b);
			ptr = get_target_for_b(*stack_b, *stack_a, &flag);
			if (flag)
			{
				while ((*stack_b))
				{
					if ((*stack_b) -> index == ptr->index)
					{
						min_num = *stack_b;
						break ;
					}
					*stack_b = (*stack_b) -> next;
				}
				min_size = ft_lstsize(min_num);
				*stack_b = start_lst;
				if (min_size > stack_size_b / 2)
				{
					while (*stack_b && (*stack_b) -> index != min_num -> index)	
					{
						count_step += rotate_stack(stack_b, "ra");
					}
				}
				else
				{	
					while (*stack_a && (*stack_b) -> index != min_num -> index)
					{
						count_step += reverse_rotate_stack(stack_b, "rra");
					}
				}
			}
		}
		count_step += push_first_sec(stack_a, stack_b, 'b');
		if (!flag)
			count_step += rotate_stack(stack_b, "rb");
		stack_size -= 1;
		stack_size_b += 1;
		count++;
		// ft_printf("stack_size = %d\n", stack_size);
		if (stack_size == 2)
		{
			// ft_printf("check\n");
			sort_stack_up(stack_a);
		}
		if (is_growth_sequence(*stack_a))
			break ;
			// printf("stack_a\n");
			// ft_print_list(*stack_a);
	}
	// ft_printf("count_step = %d\n", count_step);
	while (*stack_b)
	{
		// printf("stack_a\n");
		// ft_print_list(*stack_a);
		sort_stack_a_by_index(stack_a, stack_b, i++, &count_step);
	}
	// ft_printf("sort_stack\n");
	return (count_step);
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

t_list	*get_target_for_b(t_list *stack, t_list	*target, int *flag)
{
	t_list	*near_num;
	// int		b;
	// int		a;
	// t_list	*max_num;
	// t_list	*min_num;
	// ft_printf("stack_b");
	// ft_print_list(stack);
	near_num = stack;

	if (stack_max_num(stack)->index < target->index)
		return (stack_max_num(stack));
	if (stack_min_num(stack)->index > target->index)
	{
		*flag = 0;
		return (stack_max_num(stack));
	}
	while (stack)
	{
		// a = target->index - stack->index;
		// b = target->index - near_num->index;
		if ((target->index > stack->index && target->index - stack->index < target->index - near_num->index)
			|| (target->index - near_num->index < 0))
			near_num = stack;
		stack = stack -> next;
	}
	// ft_printf("target->index = %d\n", target->index);
	// ft_printf("near_num = %d\n", near_num->index);
	return (near_num);
}

int	check_is_circulate(t_list *stack, char **error)
{
	t_list	*next_node;
	
	while (stack -> next)
	{
		next_node = stack -> next;
		while (next_node)
		{
			if (stack->data == next_node->data)
			{
				*error = "Error: duplicated number";
				return (0);
			}
			next_node = next_node->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	check_is_num(char *str, char **error)
{
	int	i;
	
	i = -1;
	while (str[++i])
		if(!ft_isdigit((int)str[i]))
		{
			*error = "Error: not a number";
			return (0);
		}
	return (1);
}

int	free_array(char	**str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		free(str[i]);
	}
	
	free(str);
	return (1);
}

t_list	*fill_list(int ac, char	**str, char	**error)
{
	t_list *stack_a;
	t_list  *start_a;
	char	**args;
	int 	i;
	int		j;
	
	i = 1;
	j = 0;
	args = ft_split(str[i], ' ');
	if (!check_is_num(args[j], error))
		return (NULL);
	stack_a = ft_lstnew(ft_atoi(args[j++]));
	start_a = stack_a;
	stack_a -> index = -1;
	while (i++ < ac)
	{
		while (args[j])
		{
			if (!check_is_num(args[j], error) && free_array(args))
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
	if (!check_is_circulate(start_a, error))
		return (0);
	return (start_a);
}

int main(int ac, char **av)
{
	char	*error;
	int steps;
	t_list *stack_a;
	t_list *stack_b;
	int 	i;
	
	if (ac < 2)
		return (0);
	stack_b = NULL;
	steps = 0;
	i = 0;
	// while (i++ < ac)
	// 	fill_list(ft_split(av[i], ' '));
	stack_a = fill_list(ac, av, &error);
	ft_printf("%s\n", error);
	// stack_a = ft_lstnew(ft_atoi(av[i++]));
	// start_a = stack_a;
	// stack_a -> index = -1;
	// while (ac > i)
	// {
	// 	stack_a -> next = ft_lstnew(ft_atoi(av[i++]));
	// 	stack_a -> next -> index = -1;
	// 	stack_a = stack_a -> next;
	// }
	// stack_a = NULL;
	// printf("stack_a\n");
	// ft_print_list(start_a);
	// set_index(&start_a);
	// ft_printf("stack_a\n");
	// ft_print_list(start_a);
	
	steps += sort_stack(&stack_a, &stack_b);
	printf("stack_a\n");
	ft_print_list(stack_a);
	// ft_printf("steps = %d\n", steps);
}