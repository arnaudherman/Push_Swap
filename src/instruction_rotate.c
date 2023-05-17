/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:58:57 by aherman           #+#    #+#             */
/*   Updated: 2023/05/17 20:31:20 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

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

// void	rotate(t_list *stack)
// {
// 	t_element	*temp;

// 	if (!stack->first && !stack->first->nxt)
// 		return ;
// 	temp = stack->first;
// 	stack->first = stack->first->nxt;
// 	stack->first->prev = NULL;
// 	temp->prev = stack->last;
// 	temp->nxt = NULL;
// 	stack->last->nxt = temp;
// 	stack->last = temp;
// }
void	rotate(t_list *stack)
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
		rotate(stack_a);
	else if (ft_strcmp(inst, "rb") == 0)
		rotate(stack_b);
	else if (ft_strcmp(inst, "rr") == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	ft_printf("%s\n", inst);
}
