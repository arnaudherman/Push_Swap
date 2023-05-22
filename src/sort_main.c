/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:59:23 by aherman           #+#    #+#             */
/*   Updated: 2023/05/22 15:22:57 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	select_sort(char *inst, int size, t_list *stack_a, t_list *stack_b)
{
	if (ft_strcmp(inst, "pb") == 0)
	{
		if (size == 3)
		{
			sort_three(stack_a, stack_b);
			pa_pb(stack_a, stack_b, "pa");
		}
		else if (size == 4)
		{
			sort_four(stack_a, stack_b);
			instructionf(2, stack_a, stack_b, "pa", "sa");
		}
	}
}
