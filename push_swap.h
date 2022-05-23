/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:17:53 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/23 16:20:00 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include "./libft/libft.h"
# include "./ft_printff/ft_printf.h"

# define MIN_INT -2147483648
# define MAX_INT 2147483647

typedef struct s_point
{
	t_list	*target[4];
	int		stack_size;
	int		nums[4];
	int		count_step;
	int		stack_size_a;
	int		stack_size_b;
	t_list	*min_num_a;
	t_list	*min_num_b;
	int		i;
	int		j;
	t_list	*start_lst;
	int		min_size_a;
	int		max_size;
	int		min_size_b;
	int		count;
	int		flag;
	int		range_chunk;
	int		start_chunk;
	int		**tab;
}				t_var;

int		swap(t_list **a, char *s);
int		rotate_stack(t_list **lst, char	*str);
int		reverse_rotate_stack(t_list **lst, char *str);
int		rr(t_list **stack_a, t_list **stack_b, char *s);
int		rrr(t_list **stack_a, t_list **stack_b, char *s);
int		push_first_sec(t_list **a, t_list **b, char *s);
t_var	get_targets(t_list	*stack, int **tab, int count);
int		is_growth_sequence(t_list	*stack);
void	ft_print_list(t_list *lst);
void	set_index(t_list **stack);
void	sort_stack_up(t_list	**stack);
t_list	*get_index_for_push(t_list *stack, int **tab, int count);
int		**create_chunk(t_list *stack, int divide);
void	sort_stack_a_by_index(t_list **stack_a, t_list **stack_b);
t_list	*get_target_for_b(t_list *stack, t_list	*target, int *flag);
t_list	*fill_list(int ac, char	**str);
t_list	*stack_max_num(t_list *stack);
t_list	*stack_min_num(t_list *stack);
int		free_array(char	**str);
int		free_tab(int	**str);
int		sort_stack(t_list **stack_a, t_list **stack_b);
int		sort_3(t_list **stack);
int		sort_5(t_list **stack_a, t_list **stack_b);
char	*get_next_line(int fd);
int		is_integer_num(long long num);
int		check_is_num(char *str);
int		check_is_circulate(t_list *stack);
int		free_array(char	**s);
int		free_lst(t_list **lst);
int		free_tab(int **tab);

#endif