/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:41:51 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/22 14:43:04 by vaghazar         ###   ########.fr       */
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
