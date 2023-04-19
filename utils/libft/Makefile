# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecolin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 15:49:09 by ecolin            #+#    #+#              #
#    Updated: 2021/12/21 00:53:37 by ecolin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

SRC = ft_*_fd.c ft_str*.c ft_atoi.c ft_itoa.c ft_split.c ft_substr.c ft_is*.c ft_mem*.c ft_bzero.c ft_to*.c ft_calloc.c

BONUS = ft_lst*.c

CFLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(SRC)
	ar rc $(NAME) ft*.o
	make clean
bonus: fclean
	gcc $(CFLAGS) $(SRC) $(BONUS)
	ar rc $(NAME) ft*.o
	make clean
clean:
	/bin/rm -f *.o
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
