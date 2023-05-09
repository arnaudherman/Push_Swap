/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:04:54 by aherman           #+#    #+#             */
/*   Updated: 2023/05/09 12:30:30 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	is_all_digits(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || str[i] == '-'
			|| str[i] == '+' || str[i] == 0)
			return (0);
		i++;
	}
	return (1);
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
