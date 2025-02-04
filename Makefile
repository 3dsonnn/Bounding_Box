# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 09:28:49 by efinda            #+#    #+#              #
#    Updated: 2025/02/04 09:30:29 by efinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = OBX

CC = cc
MLXPATH = minilibx-linux
FLAGS = -I./$(MLXPATH) -O3 #	-Wall -Wextra -Werror
LIBS =	-L./$(MLXPATH) -lmlx -lX11 -lXext -lm
RM = rm -rf

SRC =		src/main.c 							\
		src/checks/checks.c 						\
		src/checks/map.c 						\
		src/checks/map_utils.c 						\
		src/my_mlx/my_mlx_init.c					\
		src/my_mlx/linkage.c						\
		src/my_mlx/settings.c						\
		src/my_mlx/my_mlx_hook.c					\
		src/my_mlx/my_mlx_utils.c					\
		src/movement/move_player.c					\
		src/OBX/obx.c							\
		src/OBX/paint_obx.c						\
		src/OBX/update_obx.c						\
		src/t_row/t_row.c						\
		src/t_row/t_row_aux.c						\

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
