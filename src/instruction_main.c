/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:58:57 by aherman           #+#    #+#             */
/*   Updated: 2023/02/14 16:44:21 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	instructionsf(int num, t_list *stack_a, t_list *stack_b, ...)
{
	va_list	args;
	char	*inst;
	int		size;

	va_start(args, stack_b);
	while (num > 0)
	{	
		size = stack_size(stack_a);
		inst = va_arg(args, char *);
		if (is_swap(inst))
			sa_sb(stack_a, stack_b, inst);
		else if (is_push(inst))
		{
			pa_pb(stack_a, stack_b, inst);
			select_sort(inst, size, stack_a, stack_b);
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

void	sa_sb(t_list *stack_a, t_list *stack_b, char *inst)
{
	if (ft_strcmp(inst, "sa") == 0)
		ft_swap(stack_a);
	else if (ft_strcmp(inst, "sb") == 0)
		ft_swap(stack_b);
	else if (ft_strcmp(inst, "ss") == 0)
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
	}
	ft_printf("%s\n", inst);
}

void	pa_pb(t_list *stack_a, t_list *stack_b, char *inst)
{
	if (ft_strcmp(inst, "pa") == 0)
		ft_push(stack_a, stack_b);
	else if (ft_strcmp(inst, "pb") == 0)
		ft_push(stack_b, stack_a);
	ft_printf("%s\n", inst);
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
