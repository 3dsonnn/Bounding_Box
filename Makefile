# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 09:28:49 by efinda            #+#    #+#              #
#    Updated: 2025/01/26 19:07:01 by efinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = TBR

CC = cc
MLXPATH = minilibx-linux
FLAGS = -I./$(MLXPATH) -O3 #	-Wall -Wextra -Werror
LIBS =	-L./$(MLXPATH) -lmlx -lX11 -lXext -lm
RM = rm -rf

SRC =	main.c 		\
	my_mlx.c	\

LIBFT =	libft/libft.a
MINILIBX = $(MLXPATH)/libmlx.a

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(LIBFT) $(MINILIBX) $(OBJ_DIR) $(NAME)

$(LIBFT):
	@$(MAKE) -s -C libft

$(MINILIBX):
	@$(MAKE) -C $(MLXPATH)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(LIBS) -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(MLXPATH) clean
	$(MAKE) -s -C libft clean

fclean: clean
	@$(RM) $(NAME)
	$(MAKE) -s -C libft fclean

re: fclean all
		$(MAKE) -s -C libft re

.PHONY: all clean fclean re
