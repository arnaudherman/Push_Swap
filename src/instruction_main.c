/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:58:57 by aherman           #+#    #+#             */
/*   Updated: 2023/05/09 11:55:47 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	instructionsf(int num, t_list *stack_a, t_list *stack_b, ...)
{
	va_list	args;
	char	*inst;

	va_start(args, stack_b);
	while (num > 0)
	{	
		inst = va_arg(args, char *);
		if (is_swap(inst))
			sa_sb(stack_a, stack_b, inst);
		else if (is_push(inst))
		{
			pa_pb(stack_a, stack_b, inst);
			select_sort(inst, stack_size(stack_a), stack_a, stack_b);
		}
		else if (is_rotate(inst))
			ra_rb(stack_a, stack_b, inst);
		else if (is_reverse(inst))
			rra_rrb(stack_a, stack_b, inst);
		if (check_sort(stack_a))
			return ;
		num--;
	}
}

void	instructions(int num, t_list *stack_a, t_list *stack_b, ...)
{
	va_list	args;
	char	*inst;

	va_start(args, stack_b);
	while (num > 0)
	{	
		inst = va_arg(args, char *);
		if (is_swap(inst))
			sa_sb(stack_a, stack_b, inst);
		else if (is_push(inst))
			pa_pb(stack_a, stack_b, inst);
		else if (is_rotate(inst))
			ra_rb(stack_a, stack_b, inst);
		else if (is_reverse(inst))
			rra_rrb(stack_a, stack_b, inst);
		else
			ft_printf("Error: instruction '%s' does not exist.", inst);
		num--;
	}
}
