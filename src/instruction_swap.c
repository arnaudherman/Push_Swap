/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:58:57 by aherman           #+#    #+#             */
/*   Updated: 2023/05/22 15:15:36 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	ft_swap(t_list *stack)
{
	t_element	*temp;
	int			val_temp;
	int			pos_temp;

	temp = stack->first;
	val_temp = temp->value;
	pos_temp = temp->position;
	temp->value = temp->nxt->value;
	temp->position = temp->nxt->position;
	temp = temp->nxt;
	temp->value = val_temp;
	temp->position = pos_temp;
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
