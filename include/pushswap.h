/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:28:08 by aherman           #+#    #+#             */
/*   Updated: 2023/05/09 12:15:39 by aherman          ###   ########.fr       */
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

void		free_array(char **array);
void		free_all(t_list *stack_a);
void		free_stack(t_list *stack_a);
int			is_all_digits(const char *str);
int			find_occurrences(t_list *stack);
int			pushatoi(t_list *stack, char **array);
int			check_stack(t_list *stack_a, t_list *stack_b);
int			check_args(char **array, t_list *stack_a, t_list *stack_b);
int			is_push(char *inst);
void		push(t_list *dest, t_list *src);
void		pa_pb(t_list *stack_a, t_list *stack_b, char *inst);
void		reverse_ops(t_list *stack_a, t_list *stack_b,
				int ops, char *stack_name);
void		rotate_ops(t_list *stack_a, t_list *stack_b,
				int ops, char *stack_name);
void		rotrev_ops(t_list *stack_a, t_list *stack_b,
				int ops, char *stack_name);
void		reverse(t_list *stack);
void		rra_rrb(t_list *stack_a, t_list *stack_b, char *inst);
int			rrr_ops(int ops_a, int ops_b);
int			is_rotate(char *inst);
int			is_reverse(char *inst);
void		rotate(t_list *stack);
void		ra_rb(t_list *stack_a, t_list *stack_b, char *inst);
int			is_swap(char *inst);
void		swap(t_list *stack);
void		sa_sb(t_list *stack_a, t_list *stack_b, char *inst);
void		select_sort(char *inst, int size, t_list *stack_a, t_list *stack_b);
void		instructionsf(int num, t_list *stack_a, t_list *stack_b, ...);
void		instructions(int num, t_list *stack_a, t_list *stack_b, ...);
void		error(void);
int			get_closest(t_element *element, t_list *stack_b);
int			count_op(t_list *stack, int position);
t_element	*min_ops(t_list *stack_a, t_list *stack_b, int l1, int l2);
t_best_ops	cheapest_op(t_list *stack_a, t_list *stack_b);
void		parsing(int argc, char **argv, t_list *stack_a, t_list *stack_b);
int			main(int argc, char **argv);
int			total_ops(int ops_a, int ops_b);
void		pa_sorting(t_list *stack_a, t_list *stack_b);
void		big_sort(t_list *stack_a, t_list *stack_b);
void		sort_three(t_list *stack_a, t_list *stack_b);
void		sort_four(t_list *stack_a, t_list *stack_b);
int			second_smallest(t_list *stack);
void		sort_five(t_list *stack_a, t_list *stack_b);
void		small_sort(t_list *stack_a, t_list *stack_b, int size);
void		put_index(t_list *stack);
int			get_index(t_list *stack, int pos);
void		get_position(t_list *stack);
int			*save_inarray(t_list *stack);
int			get_permutation(t_list *stack);
void		stacking(t_list *stack, int new_val);
int			stack_size(t_list *stack);
void		printlist(t_list *stack);
int			check_sort(t_list *stack);
char		**ft_split(char const *s, char c);
long		ft_atol(char *str);
int			ft_isdigit(int c);
int			ft_strcmp(char *s1, char *s2);
int			ft_abs(int n);
int			ft_iswhitespace(char c);

#endif