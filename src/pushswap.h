/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:28:08 by aherman           #+#    #+#             */
/*   Updated: 2023/02/09 22:15:13 by aherman          ###   ########.fr       */
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
void	check_args(int argc, char **argv, t_list *stack_a);
void	push_atoi(t_list *stack, char **array);
int		find_occurrences(char **array);
int		check_sort(t_list *stack);
int		atoi_push_swap(char *str);
int		ft_isspace(int a);
int		ft_isdigit(int a);
void	stacking(t_list *stack, int new_val);
t_list	*list_init(t_list *stack, int value);

#endif