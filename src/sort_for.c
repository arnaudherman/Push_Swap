/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:59:21 by aherman           #+#    #+#             */
/*   Updated: 2023/05/09 11:20:49 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	sort_four(t_list *stack_a, t_list *stack_b)
{
	int	comb;

	comb = get_permutation(stack_a);
	if (comb == 1243 || comb == 1324 || comb == 1432
		|| comb == 2143 || comb == 2314)
		instructionsf(2, stack_a, stack_b, PB, SA);
	if (comb == 1342 || comb == 3124 || comb == 4231)
		instructionsf(4, stack_a, stack_b, RRA, SA, RA, RA);
	if (comb == 2341 || comb == 3412 || comb == 3421)
		instructionsf(3, stack_a, stack_b, RRA, RRA, SA);
	if (comb == 2413 || comb == 3214)
		instructionsf(5, stack_a, stack_b, RRA, SA, RRA, RRA, SA);
	if (comb == 2134 || comb == 1423 || comb == 4312 || comb == 4321)
		instructionsf(4, stack_a, stack_b, SA, RA, RA, SA);
	if (comb == 3142 || comb == 3241)
		instructionsf(4, stack_a, stack_b, SA, RRA, SA);
	if (comb == 4123 || comb == 4213 || comb == 2431)
		instructionsf(4, stack_a, stack_b, RA, SA, RA, RA);
	if (comb == 4132)
		instructionsf(2, stack_a, stack_b, SA, PB);
}
