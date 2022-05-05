/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:17:53 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/03 15:10:44 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>


# ifndef PUSH_SWAP_H
#  define PUSH_SWAP_H

typedef struct s_list
{
	int             data;
	int				index;
	struct s_list   *next;
}               t_list;
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
int		rotate_stack(t_list **lst);
int		reverse_rotate_stack(t_list **lst);
int		push_first_sec(t_list **a, t_list **b);


#endif