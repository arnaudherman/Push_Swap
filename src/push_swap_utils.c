/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:19:41 by aherman           #+#    #+#             */
/*   Updated: 2023/05/16 16:58:20 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

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
	return (all[2] * all[1]);
}

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

int	ft_isspace(int a)
{
	if (a == '\t' || a == '\n' || a == '\v'
		|| a == '\f' || a == '\r' || a == ' ')
		return (1);
	return (0);
}
