/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:59:31 by aherman           #+#    #+#             */
/*   Updated: 2023/02/16 17:12:12 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	put_index(t_list *stack)
{
	t_element	*current;
	int			index;

	index = 0;
	current = stack->first;
	while (current)
	{
		current->index = index;
		current = current->nxt;
		index++;
	}
}

int	get_index(t_list *stack, int pos)
{
	t_element	*current;

	put_index(stack);
	current = stack->first;
	while (current)
	{
		if (current->pos == pos)
		{
			break ;
		}
		current = current->nxt;
	}
	return (current->index);
}

// void	get_position(t_list *stack)
// {
// 	t_element	*current;
// 	t_element	*comp;

// 	current = stack->first;
// 	while (current)
// 	{
// 		if (current->pos)
// 			current->pos = 0;
// 		current = current->nxt;
// 	}
// 	current = stack->first;
// 	while (current)
// 	{
// 		comp = stack->first;
// 		while (comp)
// 		{
// 			if (current->val > comp->val)
// 				current->pos--;
// 			comp = comp->nxt;
// 		}
// 		current->pos += current->pos * -2 + 1;
// 		current = current->nxt;
// 	}
// }

int	get_permutation(t_list *stack)
{	
	t_element	*current;
	int			comb;
	int			*array;
	int			i;

	array = malloc(sizeof(int) * stack_size(stack));
	current = stack->first;
	i = 0;
	while (current)
	{
		array[i++] = current->pos;
		current = current->nxt;
	}
	get_position(stack);
	current = stack->first;
	comb = 0;
	i = 0;
	while (current)
	{
		comb = comb * 10 + current->pos;
		current->pos = array[i];
		current = current->nxt;
		i++;
	}
	return (comb);
}
