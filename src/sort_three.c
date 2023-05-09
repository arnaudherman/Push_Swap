/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:59:26 by aherman           #+#    #+#             */
/*   Updated: 2023/05/09 11:20:37 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	sort_three(t_list *stack_a, t_list *stack_b)
{
	int	comb;

	comb = get_permutation(stack_a);
	if (comb == 132)
		instructionsf(2, stack_a, stack_b, RRA, SA);
	if (comb == 213)
		sa_sb(stack_a, stack_b, SA);
	if (comb == 231)
		rra_rrb(stack_a, stack_b, RRA);
	if (comb == 312)
		ra_rb(stack_a, stack_b, RA);
	if (comb == 321)
		instructionsf(2, stack_a, stack_b, SA, RRA);
}
