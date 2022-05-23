/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:08:15 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/23 13:20:44 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**create_chunk(t_list *stack, int divide)
{
	t_var	vars;

	if (!stack)
		return (0);
	vars.stack_size = ft_lstsize(stack);
	vars.range_chunk = vars.stack_size / divide;
	vars.tab = malloc(sizeof(int *) * (divide + 1));
	vars.start_chunk = 0;
	vars.i = 0;
	while (vars.i < divide)
		vars.tab[vars.i++] = (int *)malloc(sizeof(int) * 2);
	vars.tab[vars.i] = NULL;
	vars.i = 0;
	while (vars.tab[vars.i + 1] != NULL
		&& ((vars.start_chunk + vars.range_chunk) < vars.stack_size - 3))
	{
		vars.tab[vars.i][0] = vars.start_chunk;
		vars.tab[vars.i++][1] = vars.start_chunk + vars.range_chunk;
		vars.start_chunk = vars.start_chunk + vars.range_chunk;
	}
	vars.tab[vars.i][1] = vars.stack_size - 3;
	vars.tab[vars.i][0] = vars.start_chunk;
	return (vars.tab);
}
