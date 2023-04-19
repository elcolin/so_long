# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 18:15:04 by ecolin            #+#    #+#              #
#    Updated: 2022/09/25 18:07:09 by ecolin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

HEADER_SRC	=	so_long.h
HEADER_DIR	=	includes/
HEADER	=	$(addprefix $(HEADER_DIR), $(HEADER_SRC))

GNL_DIR = utils/get_next_line/
GNL = get_next_line.c get_next_line_utils.c
GPATH = $(addprefix $(GNL_DIR), $(GNL))
GOBJ = $(GPATH:.c=.o)

LIBFT_DIR = utils/libft/
LIBFT = libft.a
LPATH = $(addprefix $(LIBFT_DIR), $(LIBFT))

PRINTF_DIR = utils/ft_printf/
LIBPRINTF = libftprintf.a
PPATH = $(addprefix $(PRINTF_DIR), $(LIBPRINTF))

SRC_DIR = mandatory/
SRC = main.c map.c display.c clean.c valid.c init.c movement.c
SPATH = $(addprefix $(SRC_DIR), $(SRC))
SOBJ = $(SPATH:.c=.o)

MLX_DIR = mlx_linux/

%.o: %.c
	#$(CC) -Imlx -c $< -o $@
	$(CC) $(CFLAGS) -g -I/usr/X11/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(GOBJ) $(SOBJ)
	$(MAKE) libs
	#$(CC) $(CFLAGS) -fsanitize=address $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -L. $(LIBFT) -L. $(LIBPRINTF)
	$(CC) $(CFLAGS) -g $^ -Lmlx_linux -lmlx_Linux -L/usr/X11 -Imlx_linux -lXext -lX11 -lm -o $(NAME) $(PPATH) $(LPATH)


libs:
	cd $(LIBFT_DIR) && $(MAKE)
	cd $(PRINTF_DIR) && $(MAKE)
	cd $(MLX_DIR) && $(MAKE)
		
clean : 
		$(RM) $(SOBJ)
		$(RM) $(GOBJ)
		cd $(LIBFT_DIR) && $(MAKE) clean
		cd $(PRINTF_DIR) && $(MAKE) clean
		cd $(MLX_DIR) && $(MAKE) clean
fclean : clean
		/bin/rm -rf $(NAME)
		/bin/rm -rf $(LIBFT_DIR)$(LIBFT)
		/bin/rm -rf $(PRINTF_DIR)$(LIBPRINTF)
		cd $(LIBFT_DIR) && $(MAKE) fclean
		cd $(PRINTF_DIR) && $(MAKE) fclean
		cd $(MLX_DIR) && $(MAKE) clean
re: fclean all
