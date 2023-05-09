/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:59:18 by aherman           #+#    #+#             */
/*   Updated: 2023/05/09 11:20:55 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	second_smallest(t_list *stack)
{
	t_element	*current;
	int			smallest;
	int			second_smallest;
	int			pos;

	current = stack->first;
	smallest = stack->first->pos;
	second_smallest = 501;
	while (current != NULL)
	{
		pos = current->pos;
		if (pos < smallest)
		{
			second_smallest = smallest;
			smallest = pos;
		}
		else if (pos < second_smallest && pos != smallest)
			second_smallest = pos;
		current = current->nxt;
	}
	return (second_smallest);
}

void	sort_five(t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = second_smallest(stack_a);
	i = get_index(stack_a, i);
	if (i == 0)
		instructionsf(1, stack_a, stack_b, PB);
	if (i == 1)
		instructionsf(2, stack_a, stack_b, SA, PB);
	if (i == 2)
		instructionsf(3, stack_a, stack_b, RA, RA, PB);
	if (i == 3)
		instructionsf(3, stack_a, stack_b, RRA, RRA, PB);
	if (i == 4)
		instructionsf(2, stack_a, stack_b, RRA, PB);
}

void	small_sort(t_list *stack_a, t_list *stack_b, int size)
{
	if (size == 2)
		instructions(1, stack_a, stack_b, SA);
	else if (size == 3)
		sort_three(stack_a, stack_b);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
}
