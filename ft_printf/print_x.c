/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:22:15 by aherman           #+#    #+#             */
/*   Updated: 2022/11/10 14:34:50 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x(unsigned long n)
{
	int	len;

	len = 0;
	if (n > 15)
	{
		len += print_x(n / 16);
		len += print_x(n % 16);
	}
	else if (n > 9)
	{
		len += print_c('a' + n - 10);
	}
	else
	{
		len += print_c((n + '0'));
	}
	return (len);
}
