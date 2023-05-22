/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_dispatch.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:18:57 by aherman           #+#    #+#             */
/*   Updated: 2023/05/22 15:01:38 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	is_swap(char *inst)
{
	return (ft_strcmp(inst, "sa") == 0 || ft_strcmp(inst, "sb") == 0
		|| ft_strcmp(inst, "ss") == 0);
}

int	is_push(char *inst)
{
	return (ft_strcmp(inst, "pa") == 0 || ft_strcmp(inst, "pb") == 0);
}

int	is_rotate(char *inst)
{
	return (ft_strcmp(inst, "ra") == 0 || ft_strcmp(inst, "rb") == 0
		|| ft_strcmp(inst, "rr") == 0);
}

int	is_reverse(char *inst)
{
	return (ft_strcmp(inst, "rra") == 0 || ft_strcmp(inst, "rrb") == 0
		|| ft_strcmp(inst, "rrr") == 0);
}
