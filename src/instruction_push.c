/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:58:57 by aherman           #+#    #+#             */
/*   Updated: 2023/05/17 19:30:13 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	push(t_list *dest, t_list *src)
{
	t_element	*temp;

	if (!src->first)
		return ;
	temp = src->first;
	if (src->first == src->last)
	{
		src->first = NULL;
		src->last = NULL;
	}
	else
	{
		src->first = temp->nxt;
		src->first->prev = NULL;
	}
	temp->nxt = dest->first;
	temp->prev = NULL;
	if (dest->first)
		dest->first->prev = temp;
	dest->first = temp;
	if (!dest->last)
		dest->last = temp;
}
//A re-faire need fix 2x malloc
// void	push(t_list *dest, t_list *src)
// {
// 	t_element	*temp;

// 	temp = src->first;
// 	if (temp->nxt != NULL)
// 	{
// 		src->first = temp->nxt;
// 		src->first->prev = NULL;
// 	}
// 	else
// 	{
// 		temp->nxt = NULL;
// 		src->first = NULL;
// 		src->last = NULL;
// 	}
// 	if (dest->first != NULL)
// 	{
// 		temp->nxt = dest->first;
// 		temp->nxt->prev = temp;
// 	}
// 	else
// 		dest->last = temp;
// 	dest->first = temp;
// }

void	pa_pb(t_list *stack_a, t_list *stack_b, char *inst)
{
	if (ft_strcmp(inst, "pa") == 0)
		push(stack_a, stack_b);
	else if (ft_strcmp(inst, "pb") == 0)
		push(stack_b, stack_a);
	ft_printf("%s\n", inst);
}
