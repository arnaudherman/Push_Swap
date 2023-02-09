/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_maj_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:22:05 by aherman           #+#    #+#             */
/*   Updated: 2022/11/10 14:33:23 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_maj_x(unsigned long n)
{
	int	len;

	len = 0;
	if (n >= 0 && n <= 9)
	{
		len += print_c(n + '0');
	}
	else if (n >= 10 && n <= 15)
	{
		len += print_c('A' + n - 10);
	}
	else
	{
		len += print_maj_x(n / 16);
		len += print_maj_x(n % 16);
	}
	return (len);
}
