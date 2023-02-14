/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:04:54 by aherman           #+#    #+#             */
/*   Updated: 2023/02/14 16:44:27 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_list	*list_init(t_list *stack, int value)
{
	t_element	*element;

	element = malloc(sizeof(t_element));
	if (!stack || !element)
	{
		if (stack == NULL)
			free(element);
		if (element == NULL)
			free(stack);
		exit (EXIT_FAILURE);
	}
	element->val = value;
	element->nxt = NULL;
	element->prev = NULL;
	stack->first = element;
	return (stack);
}

void	stacking(t_list *stack, int new_val)
{
	t_element	*new_element;

	new_element = malloc(sizeof(t_element));
	if (!new_element || !stack)
		exit(EXIT_FAILURE);
	new_element->val = new_val;
	new_element->prev = stack->last;
	new_element->nxt = NULL;
	if (stack->first != NULL)
	{
		if (stack->last == NULL)
		{
			stack->first->nxt = new_element;
			stack->last = new_element;
			new_element->prev = stack->first;
		}
		stack->last->nxt = new_element;
		stack->last = new_element;
	}
	else
		stack->first = new_element;
}

int	get_positionition(t_list *stack)
{
	t_element	*current;
	t_element	*comp;
	int			comb;

	comb = 0;
	current = stack->first;
	while (current)
	{
		if (current->position)
			current->position = 0;
		current = current->nxt;
	}
	current = stack->first;
	while (current)
	{
		comp = stack->first;
		while (comp)
		{
			if (current->val > comp->val)
				current->position--;
			comp = comp->nxt;
		}
		current->position += current->position * -2 + 1;
		comb = comb * 10 + current->position;
		current = current->nxt;
	}
	return (comb);
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
