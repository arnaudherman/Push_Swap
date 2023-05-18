/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:04:54 by aherman           #+#    #+#             */
/*   Updated: 2023/05/18 22:10:57 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

long	atoi_push_swap(char *str)
{
	long	all[3];

	all[0] = 0;
	all[1] = 1;
	all[2] = 0;
	while (ft_isspace(str[all[0]]))
		all[0]++;
	if (str[all[0]] == '-' || str[all[0]] == '+')
	{
		if (str[all[0]] == '-')
			all[1] = all[1] * -1;
		all[0]++;
	}
	if (ft_isdigit(str[all[0]]))
	{
		while (str[all[0]] != '\0' && str[all[0]] <= '9' && str[all[0]] >= '0')
			all[2] = all[2] * 10 + str[all[0]++] - '0';
		return (all[2] * all[1]);
	}
	return (all[2] * all[1]);
}

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
