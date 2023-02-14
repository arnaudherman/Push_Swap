/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:28:08 by aherman           #+#    #+#             */
/*   Updated: 2023/02/14 16:51:12 by aherman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../ft_printf/include/ft_printf.h"

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

int			check_sort(t_list *stack);
int			find_occurrences(char **array);
void		push_atoi(t_list *stack, char **array);
void		check_args(int argc, char **argv, t_list *stack_a);
int			ft_isdigit(int a);
int			ft_isspace(int a);
int			atoi_push_swap(char *str);
size_t		ft_strlen(const char *s);
static void	small_mallocman(char ***s, int c);
static int	number_word(const char *s1, char c);
static char	*in_tab(const char *s1, int c1, int c2);
char		**ft_split(char const *s, char c);
void		instructionsf(int num, t_list *stack_a, t_list *stack_b, ...);
void		instructions(int num, t_list *stack_a, t_list *stack_b, ...);
void		instructions(int num, t_list *stack_a, t_list *stack_b, ...);
void		sa_sb(t_list *stack_a, t_list *stack_b, char *inst);
void		pa_pb(t_list *stack_a, t_list *stack_b, char *inst);
void		ra_rb(t_list *stack_a, t_list *stack_b, char *inst);
void		rra_rrb(t_list *stack_a, t_list *stack_b, char *inst);
void		ft_swap(t_list *stack);
void		ft_push(t_list *dst, t_list *src);
void		ft_rotate(t_list *stack);
void		ft_reverse(t_list *stack);
t_list		*list_init(t_list *stack, int value);
void		stacking(t_list *stack, int new_val);
int			get_positionition(t_list *stack);
int			stack_size(t_list *stack);
int			ft_strcmp(char *s1, char *s2);
void		sort_five(t_list *stack_a, t_list *stack_b);
void		sort_four(t_list *stack_a, t_list *stack_b);
void		small_sort(t_list *stack_a, t_list *stack_b, int size);
void		sort_three(t_list *stack_a, t_list *stack_b);
int			bigorsmall(t_list *stack_a);
void		put_index(t_list *stack);
int			get_index(t_list *stack, int pos);
void		get_position(t_list *stack);
int			get_permutation(t_list *stack);

#endif