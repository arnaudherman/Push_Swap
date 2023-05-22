/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:59:31 by aherman           #+#    #+#             */
/*   Updated: 2023/05/22 15:11:18 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	stacking(t_list *stack, int new_val)
{
	t_element	*new_element;

	new_element = malloc(sizeof(t_element));
	if (!new_element || !stack)
		exit(EXIT_FAILURE);
	new_element->value = new_val;
	new_element->prev = stack->last;
	new_element->nxt = NULL;
	if (stack->first != NULL)
	{
		stack->last->nxt = new_element;
		stack->last = new_element;
	}
	else
	{
		stack->first = new_element;
		stack->last = new_element;
	}
}

int	stack_size(t_list *stack)
{
	t_element	*current;
	int			size;

	size = 0;
	current = stack->first;
	while (current)
	{
		current = current->nxt;
		size++;
	}
	return (size);
}
