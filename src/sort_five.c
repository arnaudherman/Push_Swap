/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:59:18 by aherman           #+#    #+#             */
/*   Updated: 2023/02/14 12:40:16 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_five(t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = get_index(stack_a, 2);
	if (i == 0)
		instructionsf(1, stack_a, stack_b, PB);
	if (i == 1)
		instructionsf(2, stack_a, stack_b, SA, PB);
	if (i == 2)
		instructionsf(3, stack_a, stack_b, RA, RA, PB);
	if (i == 3)
		instructionsf(3, stack_a, stack_b, RRA, RRA, PB);
	if (i == 4)
		instructionsf(2, stack_a, stack_b, RRA, PB);
}
