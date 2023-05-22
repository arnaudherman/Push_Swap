/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:59:26 by aherman           #+#    #+#             */
/*   Updated: 2023/05/22 15:23:02 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	sort_three(t_list *stack_a, t_list *stack_b)
{
	int	comb;

	comb = get_permutation(stack_a);
	if (comb == 132)
		instructionf(2, stack_a, stack_b, "rra", "sa");
	if (comb == 213)
		sa_sb(stack_a, stack_b, "sa");
	if (comb == 231)
		rra_rrb(stack_a, stack_b, "rra");
	if (comb == 312)
		ra_rb(stack_a, stack_b, "ra");
	if (comb == 321)
		instructionf(2, stack_a, stack_b, "sa", "rra");
}
