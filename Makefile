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
CFLAGS = -Wall -Wextra 
DEBUG = -g -O0

MLX42_PATH = ./MLX42
PTF_PATH = ./ft_printf
LIB_PATH = ./libft

PTF_LIB = $(PTF_PATH)/libftprintf.a
LIBFT_LIB = $(LIB_PATH)/libft.a
MLX42_LIB = $(MLX42_PATH)/build/libmlx42.a

MLX42_INC = -I$(MLX42_PATH)/include
LIB_INC = -I$(LIB_PATH)
PTF_INC = -I$(PTF_PATH)

LD42FLAGS := $(MLX42_LIB) -ldl -lglfw -pthread -lm

SRC = src/main.c \
	  src/init.data.c \
	  src/ft_exit.c \
	  src/check_map.c \
	  src/utils.c \
	  src/new_map.c \
	  src/pars_map.c \
	  src/check_maperror.c \
	  src/check.cub.c 
      # Ajoutez tous vos autres fichiers source ici

OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

-include $(DEP)

all: $(NAME)

$(NAME): $(OBJ) $(MLX42_LIB) $(PTF_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(DEBUG) -o $@ $(OBJ) $(LD42FLAGS) $(LIBFT_LIB) $(PTF_LIB)
	@echo "$(NAME) built successfully."

$(MLX42_LIB):
	@cmake -B $(MLX42_PATH)/build -S $(MLX42_PATH) && $(MAKE) -C $(MLX42_PATH)/build -j4

$(PTF_LIB):
	$(MAKE) -C $(PTF_PATH)

$(LIBFT_LIB):
	$(MAKE) -C $(LIB_PATH)

%.o: %.c
	$(CC) $(CFLAGS) $(MLX42_INC) $(LIB_INC) $(PTF_INC) -MMD -MP -c $< -o $@

clean:
	rm -f $(OBJ) $(DEP)
	$(MAKE) -C $(PTF_PATH) clean
	$(MAKE) -C $(LIB_PATH) clean
	@if [ -f $(MLX42_PATH)/build/Makefile ]; then $(MAKE) -C $(MLX42_PATH)/build clean; fi

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PTF_PATH) fclean
	$(MAKE) -C $(LIB_PATH) fclean
	rm -rf $(MLX42_PATH)/build

re: fclean all

.PHONY: all clean fclean re $(PTF_LIB) $(LIBFT_LIB) $(MLX42_LIB)
