/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_reverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:58:57 by aherman           #+#    #+#             */
/*   Updated: 2023/05/18 22:11:34 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	reverse_ops(t_list *stack_a, t_list *stack_b, int ops, char *stack_name)
{
	if (ft_strcmp(stack_name, "a") == 0)
	{
		while (ops++ < 0)
			rra_rrb(stack_a, stack_b, "rra");
	}
	else if (ft_strcmp(stack_name, "b") == 0)
	{
		while (ops++ < 0)
			rra_rrb(stack_a, stack_b, "rrb");
	}
	else
	{
		while (ops++ < 0)
			rra_rrb(stack_a, stack_b, "rrr");
	}
}

void	rotrev_ops(t_list *stack_a, t_list *stack_b, int ops, char *stack_name)
{
	if (ops < 0)
		reverse_ops(stack_a, stack_b, ops, stack_name);
	else if (ops > 0)
		rotate_ops(stack_a, stack_b, ops, stack_name);
}

void	ft_reverse(t_list *stack)
{
	t_element	*temp;

	temp = stack->last;
	stack->last = stack->last->prev;
	stack->last->nxt = NULL;
	temp->nxt = stack->first;
	temp->prev = NULL;
	stack->first->prev = temp;
	stack->first = temp;
}

void	rra_rrb(t_list *stack_a, t_list *stack_b, char *inst)
{
	if (ft_strcmp(inst, "rra") == 0)
		ft_reverse(stack_a);
	else if (ft_strcmp(inst, "rrb") == 0)
		ft_reverse(stack_b);
	else if (ft_strcmp(inst, "rrr") == 0)
	{
		ft_reverse(stack_a);
		ft_reverse(stack_b);
	}
	ft_printf("%s\n", inst);
}
