/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:24:26 by jgamboa-          #+#    #+#             */
/*   Updated: 2023/05/08 15:05:42 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	parsing(int argc, char **argv, t_list *stack_a, t_list *stack_b)
{
	char	**split_array;

	if (argc < 2)
		return ;
	if (argc == 2)
	{
		split_array = ft_split(argv[1], ' ');
		if (check_args(split_array, stack_a, stack_b))
		{
			free_array(split_array);
			free(split_array);
			exit(1);
		}
		free_array(split_array);
		free(split_array);
	}
	else
		if (check_args(&argv[1], stack_a, stack_b))
			exit(1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));
	if (!stack_a || !stack_b)
		exit(0);
	parsing(argc, argv, stack_a, stack_b);
	if (stack_size(stack_a) <= 5)
		small_sort(stack_a, stack_b, stack_size(stack_a));
	else
		big_sort(stack_a, stack_b);
	free_all(stack_a);
	free_all(stack_b);
	return (0);
}
