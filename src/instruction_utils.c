/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:18:57 by aherman           #+#    #+#             */
/*   Updated: 2023/02/14 16:44:24 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	ft_swap(t_list *stack)
{
	t_element	*temp;
	int			val_temp;
	int			position_temp;

	temp = stack->first;
	val_temp = temp->val;
	position_temp = temp->position;
	temp->val = temp->nxt->val;
	temp->position = temp->nxt->position;
	temp = temp->nxt;
	temp->val = val_temp;
	temp->position = position_temp;
}

void	ft_push(t_list *dst, t_list *src)
{
	t_element	*temp;

	temp = src->first;
	if (temp->nxt != NULL)
	{
		src->first = temp->nxt;
		src->first->prev = NULL;
	}
	else
	{
		temp->nxt = NULL;
		src->first = NULL;
		src->last = NULL;
	}
	if (dst->first != NULL)
	{
		temp->nxt = dst->first;
		temp->nxt->prev = temp;
	}
	else
		dst->last = temp;
	dst->first = temp;
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
