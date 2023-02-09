# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherman <aherman@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 19:24:21 by aherman           #+#    #+#              #
#    Updated: 2023/02/09 19:24:21 by aherman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Werror -Wall -Wextra -fsanitize=address

RM = rm -rf

SRCS = 	src/main.c\
		src/index.c\
		src/ope1.c\
		src/ope2.c\
		src/ope3.c\
		src/ope4.c\
		src/quick_sort.c\
		src/sort_handler.c\
		src/sort_utils.c\
		ft_printf/ft_printf.a\

$(NAME) :
	make -C ft_printf
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C ft_printf

clean :
	$(RM) $(NAME)
	make clean -C ft_printf

re : fclean all
