/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:17:53 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/13 19:24:47 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>


# ifndef PUSH_SWAP_H
#  define PUSH_SWAP_H

// int count_step = 0;

typedef struct s_list
{
	int             data;
	int				index;
	struct s_list   *next;
}               t_list;

typedef struct s_point
{
	t_list	*target[4];
	int		first;
	int		second;
	int		third;
	int		forth;
	int		stack_size;
	int		nums[4];
}				var;


void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
char	**ft_split(char const *s, char c);
int		ft_printf(const char *from, ...);
int		ft_atoi(const char *nptr);

int		swap_a(t_list **a);
int		swap_b(t_list **a);
int		rotate_stack(t_list **lst, char	*str);
int		reverse_rotate_stack(t_list **lst, char *str);
int		rr(t_list **stack_a, t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);
int		push_first_sec(t_list **a, t_list **b);
var		get_targets(t_list	*stack, int **tab, int count);
int		is_growth_sequence(t_list	*stack);
void    ft_print_list(t_list *lst);
void	set_index(t_list **stack);
int		sort_stack_up(t_list	**stack);
int		get_index_for_push(t_list *stack, int **tab, int count);
int		**create_chunk(t_list *stack);
int		sort_stack_a_by_index(t_list **stack_a,t_list **stack_b, int index, int *count_step);



#endif