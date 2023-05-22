/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:59:18 by aherman           #+#    #+#             */
/*   Updated: 2023/05/22 15:22:41 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	second_smallest(t_list *stack)
{
	t_element	*current;
	int			smallest;
	int			second_smallest;
	int			position;

	current = stack->first;
	smallest = stack->first->position;
	second_smallest = 501;
	while (current != NULL)
	{
		position = current->position;
		if (position < smallest)
		{
			second_smallest = smallest;
			smallest = position;
		}
		else if (position < second_smallest && position != smallest)
			second_smallest = position;
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
		instructionf(1, stack_a, stack_b, "pb");
	if (i == 1)
		instructionf(2, stack_a, stack_b, "sa", "pb");
	if (i == 2)
		instructionf(3, stack_a, stack_b, "ra", "ra", "pb");
	if (i == 3)
		instructionf(3, stack_a, stack_b, "rra", "rra", "pb");
	if (i == 4)
		instructionf(2, stack_a, stack_b, "rra", "pb");
}

void	small_sort(t_list *stack_a, t_list *stack_b, int size)
{
	if (size == 2)
		instruction(1, stack_a, stack_b, "sa");
	else if (size == 3)
		sort_three(stack_a, stack_b);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
}
