/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:09:39 by aherman           #+#    #+#             */
/*   Updated: 2023/05/08 15:27:54 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

long	ft_atol(char *str)
{
	long	i[3];

	i[0] = 0;
	i[1] = 1;
	i[2] = 0;
	while (ft_iswhitespace(str[i[0]]))
		i[0]++;
	if (str[i[0]] == '-' || str[i[0]] == '+')
	{
		if (str[i[0]++] == '-')
			i[1] = -1;
	}
	while (str[i[0]] && ft_isdigit(str[i[0]]))
		i[2] = i[2] * 10 + str[i[0]++] - '0';
	return (i[2] * i[1]);
}

int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
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

int	ft_iswhitespace(char c)
{
	if (c == '\t' || c == '\v' || c == '\n' || c == '\r'
		|| c == '\f' || c == ' ')
		return (1);
	return (0);
}
