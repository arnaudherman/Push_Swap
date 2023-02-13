# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 19:24:21 by aherman           #+#    #+#              #
#    Updated: 2023/02/13 13:04:36 by aherman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Werror -Wall -Wextra -fsanitize=address

RM = rm -rf

SRCS = 	src/push_swap.c\
		src/check_args.c\
		src/check_atoi.c\
		src/list_utils.c\
		src/check_split.c\
		src/instruction_main.c\
		src/instruction_utils.c\
		src/sort_big.c\
		src/sort_five.c\
		src/sort_for.c\
		src/sort_three.c\
		src/sort_main.c\
		src/sort_utils.c\
		ft_printf/ft_printf.a\

$(NAME) :
	${MAKE} -sC ./ft_printf all
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C ft_printf

clean :
	$(RM) $(NAME)
	make clean -C ft_printf
	
re : fclean all
