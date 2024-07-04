# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 09:39:42 by bloisel           #+#    #+#              #
#    Updated: 2024/06/20 11:14:08y bloisel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -O0

MLX_DIR = ./MLX42
MLX_LIB = $(MLX_DIR)/build/libmlx42.a
MLX_INC = $(MLX_DIR)/include

SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf
MINILIBX_DIR = ./minilibx-linux

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEP = $(OBJ:.o=.d)

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a

# Ajout du flag -s pour rendre make plus silencieux
MAKEFLAGS += --silent

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(MINILIBX) $(MLX_LIB) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(MLX_LIB) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -L$(MINILIBX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MLX_INC) -I$(MINILIBX_DIR) -MMD -MP -c $< -o $@

$(LIBFT):
	make -s -C $(LIBFT_DIR)

$(PRINTF):
	make -s -C $(PRINTF_DIR)

$(MINILIBX):
	make -s -C $(MINILIBX_DIR)

$(MLX_LIB):
	cmake -B $(MLX_DIR)/build $(MLX_DIR) > /dev/null
	make -s -C $(MLX_DIR)/build

clean:
	rm -f $(OBJ) $(DEP)
	rm -rf $(OBJ_DIR)
	rm -f $(SRC_DIR)/*.o $(SRC_DIR)/*.d
	make -s -C $(LIBFT_DIR) clean
	make -s -C $(PRINTF_DIR) clean
	make -s -C $(MINILIBX_DIR) clean
	rm -rf $(MLX_DIR)/build

fclean: clean
	rm -f $(NAME)
	make -s -C $(LIBFT_DIR) fclean
	make -s -C $(PRINTF_DIR) fclean
	make -s -C $(MINILIBX_DIR) clean
	rm -f $(MLX_LIB)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re $(LIBFT) $(PRINTF) $(MINILIBX) $(MLX_LIB)
