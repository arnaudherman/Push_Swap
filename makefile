# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 19:24:21 by aherman           #+#    #+#              #
#    Updated: 2023/05/08 15:25:30 by aherman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS := src/push_swap.c\
		src/check_utils.c\
		src/free_utils.c\
		src/instruction_push.c\
		src/instruction_reverse.c\
		src/instruction_rotate.c\
		src/instruction_swap.c\
		src/instructions.c\
		src/operations_opti.c\
		src/sort_bigstack.c\
		src/sort_smallstack.c\
		src/sort_utils.c\
		src/stack_utils.c\
		src/libft_split.c\
		src/libft.c\

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
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
