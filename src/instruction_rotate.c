/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:58:57 by aherman           #+#    #+#             */
/*   Updated: 2023/05/18 22:12:16 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	rotate_ops(t_list *stack_a, t_list *stack_b, int ops, char *stack_name)
{
	if (ft_strcmp(stack_name, "a") == 0)
	{
		while (ops-- > 0)
			ra_rb(stack_a, stack_b, "ra");
	}
	else if (ft_strcmp(stack_name, "b") == 0)
	{
		while (ops-- > 0)
			ra_rb(stack_a, stack_b, "rb");
	}
	else
	{
		while (ops-- > 0)
			ra_rb(stack_a, stack_b, "rr");
	}
}

int	rrr_ops(int ops_a, int ops_b)
{
	int	ops_ab;

	ops_ab = 0;
	if ((ops_a > 0 && ops_b > 0) || (ops_a < 0 && ops_b < 0))
	{
		if (ops_a > ops_b)
		{
			ops_ab = ops_b;
			ops_a = ops_a - ops_b;
			ops_b = 0;
		}
		else
		{
			ops_ab = ops_a;
			ops_b = ops_b - ops_a;
			ops_a = 0;
		}
	}
	return (ops_ab);
}

void	ft_rotate(t_list *stack)
{
	t_element	*temp;

	temp = stack->first;
	stack->first = stack->first->nxt;
	stack->first->prev = NULL;
	temp->prev = stack->last;
	temp->nxt = NULL;
	stack->last->nxt = temp;
	stack->last = temp;
}

void	ra_rb(t_list *stack_a, t_list *stack_b, char *inst)
{
	if (ft_strcmp(inst, "ra") == 0)
		ft_rotate(stack_a);
	else if (ft_strcmp(inst, "rb") == 0)
		ft_rotate(stack_b);
	else if (ft_strcmp(inst, "rr") == 0)
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
	ft_printf("%s\n", inst);
}
