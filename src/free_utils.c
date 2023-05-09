/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:09:39 by aherman           #+#    #+#             */
/*   Updated: 2023/05/08 15:10:33 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
}

void	free_all(t_list *stack_a)
{
	if (stack_a->first)
		free_stack(stack_a);
	free(stack_a);
}

void	free_stack(t_list *stack_a)
{
	t_element	*current;
	t_element	*next;

	current = stack_a->first;
	while (current)
	{
		next = current->nxt;
		free(current);
		current = next;
	}
	stack_a->first = NULL;
	stack_a->last = NULL;
}
