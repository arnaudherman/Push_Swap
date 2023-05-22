/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:59:21 by aherman           #+#    #+#             */
/*   Updated: 2023/05/22 15:22:54 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	sort_four(t_list *stack_a, t_list *stack_b)
{
	int	comb;

	comb = get_permutation(stack_a);
	if (comb == 1243 || comb == 1324 || comb == 1432
		|| comb == 2143 || comb == 2314)
		instructionf(2, stack_a, stack_b, "pb", "sa");
	if (comb == 1342 || comb == 3124 || comb == 4231)
		instructionf(4, stack_a, stack_b, "rra", "sa", "ra", "ra");
	if (comb == 2341 || comb == 3412 || comb == 3421)
		instructionf(3, stack_a, stack_b, "rra", "rra", "sa");
	if (comb == 2413 || comb == 3214)
		instructionf(5, stack_a, stack_b, "rra", "sa", "rra", "rra", "sa");
	if (comb == 2134 || comb == 1423 || comb == 4312 || comb == 4321)
		instructionf(4, stack_a, stack_b, "sa", "ra", "ra", "sa");
	if (comb == 3142 || comb == 3241)
		instructionf(4, stack_a, stack_b, "sa", "rra", "sa");
	if (comb == 4123 || comb == 4213 || comb == 2431)
		instructionf(4, stack_a, stack_b, "ra", "sa", "ra", "ra");
	if (comb == 4132)
		instructionf(2, stack_a, stack_b, "sa", "pb");
}
