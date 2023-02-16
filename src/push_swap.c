/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:47:29 by aherman           #+#    #+#             */
/*   Updated: 2023/02/16 12:03:26 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_a;

	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));
	check_args(argc, argv, stack_a);
	get_position(stack_a);
	if (check_sort(stack_a))
		exit(1);
	size_a = stack_size(stack_a);
	if (size_a < 6)
		small_sort(stack_a, stack_b, size_a);
	else
		big_sort(stack_a, stack_b);
	return (0);
}
