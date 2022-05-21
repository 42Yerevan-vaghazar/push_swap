/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:26:21 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/21 20:48:23 by vaghazar         ###   ########.fr       */
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


// void	sort_with_rotate()
// {
// 	while (min_size_b >= stack_size_b / 2 && min_size_a >= stack_size_a / 2
// 		&& *stack_a && (*stack_a) -> index != min_num_a -> index
// 		&& *stack_b && (*stack_b)->index != min_num_b->index)
// 		count_step += rr(stack_a, stack_b);
// 	while (min_size_b >= stack_size_b / 2 && *stack_b && (*stack_b) -> index != min_num_b -> index)
// 		count_step += rotate_stack(stack_b, "rb");
// 	while (min_size_a >= stack_size_a / 2 && *stack_a && (*stack_a) -> index != min_num_a -> index)
// 	{
// 		count_step += rotate_stack(stack_a, "ra");
// 	}
// }


t_list	*get_target_for_b(t_list *stack, t_list	*target, int *flag)
{
	t_list	*near_num;
	int		b;
	int		a;
	
	near_num = stack;
	if (stack && stack_max_num(stack)->index < target->index)
		return (stack_max_num(stack));
	if (stack && stack_min_num(stack)->index > target->index)
	{
		if (ft_lstsize(stack) > 2)
			*flag = 0;
		return (stack_max_num(stack));
	}
	while (stack && target->index < stack->index)
		stack = stack->next;
	near_num = stack;
	while (stack)
	{
		a = target->index - stack->index;
		b = target->index - near_num->index;
		if ((target->index > stack->index && target->index - stack->index < target->index - near_num->index))
			near_num = stack;
		stack = stack -> next;
	}
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

int	is_integer_num(long long num)
{
	if (num <  MIN_INT ||  num > MAX_INT)
	{
		ft_printf("Error: out of range");
		return (0);
	}
	return (1);
}

void	correct_stacks(var *vars, t_list **stack_a, t_list	**stack_b)
{
	while (vars->min_size_b >= vars->stack_size_b / 2 && vars->min_size_a >= vars->stack_size_a / 2
		&& *stack_a && (*stack_a) -> index != vars->min_num_a -> index
		&& *stack_b && (*stack_b)->index != vars->min_num_b->index)
		rr(stack_a, stack_b);
	while (vars->min_size_b >= vars->stack_size_b / 2 && *stack_b && (*stack_b) -> index != vars->min_num_b -> index)
		rotate_stack(stack_b, "rb");
	while (vars->min_size_a >= vars->stack_size_a / 2 && *stack_a && (*stack_a) -> index != vars->min_num_a -> index)
		rotate_stack(stack_a, "ra");
	while (vars->min_size_a <= vars->stack_size_a / 2 && vars->min_size_b <= vars->stack_size_b / 2 
		&& *stack_b && (*stack_b) -> index != vars->min_num_b -> index 
		&& *stack_a && (*stack_a) -> index != vars->min_num_a -> index)
		rrr(stack_a, stack_b);
	while (vars->min_size_b <= vars->stack_size_b / 2 && *stack_b && (*stack_b) -> index != vars->min_num_b -> index)
		reverse_rotate_stack(stack_b, "rrb");
	while (vars->min_size_a <= vars->stack_size_a / 2 && *stack_a && (*stack_a) -> index != vars->min_num_a -> index)
		reverse_rotate_stack(stack_a, "rra");
}

void	initialize_vars(var *vars, t_list *stack_a)
{
	vars->count = 0;
	vars->i = 0;
	vars->flag = 1;
	vars->min_num_a = 0;
	vars->min_num_b = 0;
	vars->tab = create_chunk(stack_a, 1);
	vars->stack_size_a = ft_lstsize(stack_a);
	vars->max_size = vars->stack_size_a - 1;
	
}

void	declare_args(var *vars, t_list **stack_a, t_list **stack_b)
{
	vars->flag = 1;
	vars->start_lst = *stack_a;
	if (vars->count > vars->tab[vars->i][1])
		vars->i++;
	vars->stack_size_b = ft_lstsize(*stack_b);
	vars->stack_size_a = ft_lstsize(*stack_a);
	vars->min_num_a = get_index_for_push(*stack_a, vars->tab, vars->i);
	vars->min_num_b = get_target_for_b(*stack_b, vars->min_num_a, &(vars->flag));
	vars->min_size_a = ft_lstsize(vars->min_num_a);
	vars->min_size_b = ft_lstsize(vars->min_num_b);
}

int	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int		count_step = 0;
	var		vars;
	
	initialize_vars(&vars, *stack_a);
	while (1)
	{
		declare_args(&vars, stack_a, stack_b);
		correct_stacks(&vars, stack_a, stack_b);
		push_first_sec(stack_a, stack_b, "pb");
		if (!vars.flag)
			rotate_stack(stack_b, "rb");
		vars.stack_size_a -= 1;
		vars.stack_size_b += 1;
		vars.count++;
		if (vars.stack_size_b == 2 && (*stack_b)->index < (*stack_b)->next->index)
			swap_b(stack_b);
		if (vars.stack_size_a == 2)
		{
			sort_stack_up(stack_a);
			break;
		}
	}
	while (*stack_b)	
		sort_stack_a_by_index(stack_a, stack_b, vars.i++, &count_step);
	return (count_step);
}

// int sort_3(t_list **stack)
// {
// 	if ((*stack)->index > (*stack)->next->index && (*stack)->index < ft_lstlast(*stack)->index)
// 		swap_a(stack);
// 	else if ((*stack)->index > (*stack)->next->index && (*stack)->index > ft_lstlast(*stack)->index)
// 		rotate_stack(stack, "ra");
// 	else if ((*stack)->index < (*stack)->next->index && (*stack)->next->index > ft_lstlast(*stack)->index)
// 		reverse_rotate_stack(stack, "rra");
// 	else if ((*stack)->index > (*stack)->next->index && (*stack)->next->index > ft_lstlast(*stack)->index)
// 	{
// 		swap_a(stack);
// 		reverse_rotate_stack(stack, "rra");
// 	}
// 	else if ((*stack)->index < (*stack)->next->index && (*stack)->next->index > ft_lstlast(*stack)->index
// 			&& (*stack)->index < ft_lstlast(*stack))
// 	{
// 		swap_a(stack);
// 		rotate_stack(stack, "ra");
// 	}
// }

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
	// printf("stack_a\n");m
	// ft_print_list(stack_a);
	if (stack_a == NULL)
		exit (1);
	// if ()
	steps += sort_stack(&stack_a, &stack_b);
	// ft_printf("steps = %d\n", steps);
	// printf("stack_a\n");
	// ft_print_list(stack_a);

	
	return (0);
}