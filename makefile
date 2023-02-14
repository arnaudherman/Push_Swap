# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 19:24:21 by aherman           #+#    #+#              #
#    Updated: 2023/02/14 16:03:57 by aherman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LPUSH_SWAP = push_swap.a

libmerge = libtool -static -o
CC = gcc

CFLAGS = -Werror -Wall -Wextra -fsanitize=address

RM = rm -rf

SRCS = 	src/push_swap.c\
		src/push_swap_utils.c\
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

OBJS = ${SRCS:.c=.o}

$(NAME) : $(OBJS)
	${MAKE} -C ft_printf
	gcc $(CFLAGS) $(OBJS) -o $(NAME)
	ar rcs ${NAME} ${OBJS}

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C ft_printf

clean :
	$(RM) $(NAME) ${OBJS}
	make clean -C ft_printf
	
re : fclean all

