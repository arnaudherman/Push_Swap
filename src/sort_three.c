/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:59:26 by aherman           #+#    #+#             */
/*   Updated: 2023/02/13 13:06:50 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bigorsmall(t_list *stack_a)
{
	t_element	*current;
	int			is_big_or_small;

	current = stack_a->first;
	is_big_or_small = 0;
	while (current)
	{
		if (current->nxt)
		{
			if (current->val > current->nxt->val)
			{
				is_big_or_small *= 10;
				is_big_or_small += 1;
			}
			else
			{
				is_big_or_small *= 10;
				is_big_or_small += 2;
			}
		}
		current = current->nxt;
	}
	if (stack_a->last->val > stack_a->first->val)
	{
		is_big_or_small *= 10;
		is_big_or_small += 1;
	}
	else
	{
		is_big_or_small *= 10;
		is_big_or_small += 2;
	}
	return (is_big_or_small);
}

void	sort_three(t_list *stack_a, t_list *stack_b)
{
	int	is_big_or_small;

	is_big_or_small = bigorsmall(stack_a);
	if (is_big_or_small == 112)
	{
		ra_rb(stack_a, stack_b, "ra");
		sa_sb(stack_a, stack_b, "sa");
	}
	if (is_big_or_small == 121)
		sa_sb(stack_a, stack_b, "sa");
	if (is_big_or_small == 122)
		ra_rb(stack_a, stack_b, "ra");
	if (is_big_or_small == 211)
	{
		sa_sb(stack_a, stack_b, "sa");
		ra_rb(stack_a, stack_b, "ra");
	}
	if (is_big_or_small == 212)
		ra_rb(stack_a, stack_b, "rra");
}
