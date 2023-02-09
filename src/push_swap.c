/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:47:29 by aherman           #+#    #+#             */
/*   Updated: 2023/02/09 21:44:23 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_exit(void)
{
	ft_printf ("Error\n");
	exit (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));
	check_args(argc, argv, stack_a);
	sort_main(stack_a, stack_b);
}
