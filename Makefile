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

# Nom de l'exécutable
NAME = cub3d

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -O0

# Répertoires
SRC_DIR = src
OBJ_DIR = obj
MINI_LX = ./minilibx-linux
LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf

# Sources et objets
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Bibliothèques
MINI_LX_LIB = $(MINI_LX)/libmlx.a
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Flags pour MiniLibX
MLXFLAGS = -L$(MINI_LX) -lmlx -lm -lX11 -lXext -L/usr/lib

# Cible par défaut
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(MINI_LX_LIB)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(MINI_LX) -lmlx -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -lm -lX11 -lXext

# Compilation des objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(MINI_LX) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -MMD -MP -c $< -o $@

# Bibliothèques
$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(MINI_LX_LIB):
	make -C $(MINI_LX)

# Nettoyage
clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	make -C $(MINI_LX) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	make -C $(MINI_LX) clean

re: fclean all

-include $(OBJ:.o=.d)

.PHONY: all clean fclean re
