# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecolin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 15:49:09 by ecolin            #+#    #+#              #
#    Updated: 2022/01/07 18:19:41 by ecolin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRC = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o ft_strlen.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_strlcpy.o ft_strlcat.o ft_strchr.o ft_strrchr.o ft_strncmp.o ft_memchr.o ft_memcmp.o ft_strnstr.o ft_calloc.o ft_strdup.o ft_atoi.o ft_substr.o ft_strjoin.o ft_itoa.o ft_split.o ft_strtrim.o ft_strmapi.o ft_striteri.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_dizcount.o ft_abs.o

all: $(NAME)

$(NAME): $(SRC)
	ar rc $(NAME) $^
%.o: %.c
	$(CC) $^ -c $(CFLAGS)

.PHONY: clean fclean

clean:
	/bin/rm -f *.o
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
