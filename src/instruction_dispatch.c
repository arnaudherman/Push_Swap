/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_dispatch.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:18:57 by aherman           #+#    #+#             */
/*   Updated: 2023/05/09 12:00:22 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	is_swap(char *inst)
{
	return (ft_strcmp(inst, SA) == 0 || ft_strcmp(inst, SB) == 0
		|| ft_strcmp(inst, SS) == 0);
}

int	is_push(char *inst)
{
	return (ft_strcmp(inst, PA) == 0 || ft_strcmp(inst, PB) == 0);
}

int	is_rotate(char *inst)
{
	return (ft_strcmp(inst, RA) == 0 || ft_strcmp(inst, RB) == 0
		|| ft_strcmp(inst, RR) == 0);
}

int	is_reverse(char *inst)
{
	return (ft_strcmp(inst, RRA) == 0 || ft_strcmp(inst, RRB) == 0
		|| ft_strcmp(inst, RRR) == 0);
}
