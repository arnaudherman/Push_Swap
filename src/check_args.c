/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:04:54 by aherman           #+#    #+#             */
/*   Updated: 2023/05/19 10:29:42 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	check_sort(t_list *stack)
{
	t_element	*current;
	int			is_sorted;

	is_sorted = 1;
	current = stack->first;
	while (current)
	{
		if (current->nxt)
		{
			if (current->val > current->nxt->val)
				is_sorted = 0;
		}
		current = current->nxt;
	}
	return (is_sorted);
}

int	find_occurrences(t_list *stack)
{
	t_element	*current;
	t_element	*comp;

	current = stack->first;
	while (current)
	{
		comp = current->nxt;
		while (comp)
		{
			if (current->pos == comp->pos)
				return (1);
			comp = comp->nxt;
		}
		current = current->nxt;
	}
	return (0);
}

int	check_stack(t_list *stack_a, t_list *stack_b)
{
	get_position(stack_a);
	if (find_occurrences(stack_a))
	{
		free_all(stack_a);
		free_all(stack_b);
		error();
		return (1);
	}
	if (check_sort(stack_a))
	{
		free_all(stack_a);
		free_all(stack_b);
		return (1);
	}
	return (0);
}

int	check_args(char **array, t_list *stack_a, t_list *stack_b)
{
	if (pushatoi(stack_a, array))
	{
		error();
		return (1);
	}
	if (check_stack(stack_a, stack_b))
		return (1);
	return (0);
}
