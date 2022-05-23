/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:41:51 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/23 13:20:19 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	free_lst(t_list **lst)
{
	t_list	*tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)-> next;
		free(*lst);
		*lst = tmp;
	}
	return (1);
}

void	ft_print_list(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		ft_printf("|i = %d # ", lst -> index);
		ft_printf("%d |", lst -> data);
		lst = lst -> next;
	}
	ft_printf("\n-----------------\n");
}
