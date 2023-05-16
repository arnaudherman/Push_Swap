/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:04:54 by aherman           #+#    #+#             */
/*   Updated: 2023/05/16 22:10:57 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	pushatoi(t_list *stack, char **array)
{
	size_t	i;
	long	val;

	i = 0;
	val = 0;
	while (array[i])
	{
		val = atoi_push_swap(array[i]);
		if (val > INT_MAX || val < INT_MIN || !is_all_digits(array[i]))
			return (1);
		stacking(stack, (int)val);
		i++;
	}
	return (0);
}
