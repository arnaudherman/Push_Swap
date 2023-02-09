/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:28:08 by aherman           #+#    #+#             */
/*   Updated: 2023/02/09 19:28:08 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../ft_printf/ft_printf.h"

typedef struct s_element
{
	int value;
	int position;
	struct s_element	*prev;
	struct s_element	*nxt;
} t_element;

typedef struct s_list
{
	struct	s_element	*first;
	struct	s_element	*last;
} t_list;

#endif