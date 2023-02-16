/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:04:54 by aherman           #+#    #+#             */
/*   Updated: 2023/02/16 12:10:40 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	check_sort(t_list *stack)
{
	t_element	*current;
	int			is_sorted;

	is_sorted = 1;
	current = stack->first;
	while (current)
	{
		if (current->nxt)
		{
			if (current->val > current->nxt->val)
				is_sorted = 0;
		}
		current = current->nxt;
	}
	return (is_sorted);
}

int	find_occurrences(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = i + 1;
		while (array[j])
		{
			if (!ft_strcmp(array[i], array[j]))
			{
				ft_printf("Error\n");
				exit (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	push_atoi(t_list *stack, char **array)
{
	size_t	c1;

	c1 = 1;
	while (array[c1])
	{
		stacking(stack, atoi_push_swap(array[c1]));
		c1++;
	}
}

void	check_args(int argc, char **argv, t_list *stack_a)
{
	char	**array;

	if (argc < 2)
		exit (1);
	if (argc == 2)
	{
		array = malloc(sizeof(array) * argc + 1);
		array = ft_split(argv[1], ' ');
		find_occurrences(array);
		push_atoi(stack_a, array);
	}
	else
	{
		find_occurrences(&argv[1]);
		push_atoi(stack_a, &argv[1]);
	}
}
