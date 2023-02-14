/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:04:54 by aherman           #+#    #+#             */
/*   Updated: 2023/02/14 12:28:22 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_isdigit(int a)
{
	if (a >= 48 && a <= 57)
		return (1);
	return (0);
}

int	ft_isspace(int a)
{
	if (a == '\t' || a == '\n' || a == '\v'
		|| a == '\f' || a == '\r' || a == ' ')
		return (1);
	return (0);
}

int	atoi_push_swap(char *str)
{
	int	all[3];

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
	else
	{
		ft_printf("Error\n");
		exit (1);
	}
	return (all[2] * all[1]);
}
