/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:28:08 by aherman           #+#    #+#             */
/*   Updated: 2023/02/21 12:00:36 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdio.h>
# include <stdlib.h>
# include "../ft_printf/include/ft_printf.h"

/* Macros */
# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

/* Structures */
typedef struct s_element	t_element;
struct s_element
{
	int			val;
	int			pos;
	int			index;
	t_element	*prev;
	t_element	*nxt;
};

typedef struct s_list
{
	t_element	*first;
	t_element	*last;
}	t_list;

typedef struct s_instructions
{
	char	*instruction;
}	t_instructions;

typedef struct s_best_ops
{
	t_element	*best_pos;
	int			closest_pos;
	int			ops_a;
	int			ops_b;
	int			ops_ab;
}	t_best_ops;

t_list		*list_init(t_list *stack, int value);
void		stacking(t_list *list, int new_val);
void		deletion(t_list *list);
void		printlist(t_list *list);
void		printstacks(t_list *list_a, t_list *list_b);
int			arrlen(char **str);
int			find_occurrences(char **array);
int			check_sort(t_list *stack);
void		check_args(int argc, char **argv, t_list *stack_a);
void		pushatoi(t_list *stack, char **array);
int			is_swap(char *inst);
int			is_push(char *inst);
int			is_rotate(char *inst);
int			is_reverse(char *inst);
void		instructions(int num, t_list *stack_a, t_list *stack_b, ...);
void		instructionsf(int num, t_list *stack_a, t_list *stack_b, ...);
void		ft_swap(t_list *stack);
void		ft_push(t_list *dest, t_list *src);
void		ft_rotate(t_list *stack);
void		ft_reverse(t_list *stack);
void		sa_sb(t_list *stack_a, t_list *stack_b, char *inst);
void		pa_pb(t_list *stack_a, t_list *stack_b, char *inst);
void		ra_rb(t_list *stack_a, t_list *stack_b, char *inst);
void		rra_rrb(t_list *stack_a, t_list *stack_b, char *inst);
void		sort_three(t_list *stack_a, t_list *stack_b);
void		sort_four(t_list *stack_a, t_list *stack_b);
void		sort_five(t_list *stack_a, t_list *stack_b);
void		small_sort(t_list *stack_a, t_list *stack_b, int size);
t_element	*min_ops(t_list *stack_a, t_list *stack_b, int l1, int l2);
t_best_ops	cheapest_op(t_list *stack_a, t_list *stack_b);
int			rrr_ops(int ops_a, int ops_b);
int			get_index(t_list *stack, int pos);
int			stack_size(t_list *stack);
int			get_permutation(t_list *stack);
int			count_op(t_list *stack, int position);
int			get_closest(t_element *element, t_list *stack_b);
int			total_ops(int ops_a, int ops_b);
void		get_position(t_list *stack);
void		big_sort(t_list *stack_a, t_list *stack_b);
void		rotate_ops(t_list *stack_a, t_list *stack_b, \
				int ops, char *stack_name);
void		put_index(t_list *stack);
char		**ft_split(char const *s, char c);
int			ft_strcmp(char *s1, char *s2);
int			atoi_push_swap(char *str);
int			ft_abs(int n);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);

int	*save_inarray(t_list *stack);


#endif
