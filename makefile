# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 19:24:21 by aherman           #+#    #+#              #
#    Updated: 2023/05/18 12:50:34 by aherman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS := src/push_swap.c\
		src/push_swap_utils.c\
		src/check_args.c\
		src/check_atoi.c\
		src/free_utils.c\
		src/check_split.c\
		src/instruction_main.c\
		src/instruction_swap.c\
		src/instruction_rotate.c\
		src/instruction_reverse.c\
		src/instruction_push.c\
		src/instruction_dispatch.c\
		src/sort_big.c\
		src/sort_five.c\
		src/sort_for.c\
		src/sort_three.c\
		src/sort_main.c\
		src/sort_utils.c\
		src/sort_big_opti.c\
		src/sort_big_utils.c\

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. 
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
OBJS = $(SRCS:.c=.o)


all: ${NAME} ${CHECK} ${OBJS}
${NAME}: ${OBJS}
	@${MAKE} -C ./ft_printf
	@${CC} ${CFLAGS} ${OBJS} ./ft_printf/ft_printf.a -o ${NAME}

${CHECK}: ${CHECK_OBJS} 
	@${CC} ${CFLAGS} ${CHECK_OBJS} ./ft_printf/ft_printf.a -o ${CHECK}

clean: 
	@${MAKE} -C ./ft_printf fclean
	@${RM} ${OBJS}
	@${RM} ${CHECK_OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${CHECK}

re: fclean all
