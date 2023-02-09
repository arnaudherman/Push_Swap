/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:28:08 by aherman           #+#    #+#             */
/*   Updated: 2023/02/09 21:52:04 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../ft_printf/ft_printf.h"

typedef struct s_element
{
	int					val;
	int					position;
	struct s_element	*prev;
	struct s_element	*nxt;
}	t_element;

typedef struct s_list
{
	struct s_element	*first;
	struct s_element	*last;
}	t_list;

int		main(int argc, char **argv);
void	ft_exit(void);
int		atoi_push_swap(char *str);
void	check_args(int argc, char **argv, t_list *stack_a);

#endif