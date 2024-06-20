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

CFLAGS = -Wall
DEBUG = -g -O0


MLX_PATH = ./minilibx-linux
PTF_PATH = ./ft_printf
LIB_PATH = ./libft

PTF_LIB = $(PTF_PATH)/libftprintf.a
LIBFT_LIB = $(LIB_PATH)/libft.a
MLX_LIB = $(MLX_PATH)/libmlx.a


MLX_INC = -I$(MLX_PATH)

LIB_INC = -I$(LIB_PATH)

PTF_INC = -I$(PTF_PATH)

# Detect the OS
UNAME_S := $(shell uname -s)

# Set OS-specific flags
ifeq ($(UNAME_S), Darwin)
    LDFLAGS = -framework AppKit -framework OpenGL -L$(MLX_PATH) -lmlx
else
    LDFLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lbsd
endif

SRC = src/main.c \
      # add other source files here

OBJ = $(SRC:.c=.o)

# Compile all libraries before compiling the main project
all: $(MLX_LIB) $(PTF_LIB) $(LIBFT_LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(DEBUG) -o $@ $^ $(LDFLAGS) $(LIBFT_LIB) $(PTF_LIB)

$(MLX_LIB):
	$(MAKE) -C $(MLX_PATH)

$(PTF_LIB):
	$(MAKE) -C $(PTF_PATH)

$(LIBFT_LIB):
	$(MAKE) -C $(LIB_PATH)

%.o: %.c
	$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MLX_PATH) clean
	$(MAKE) -C $(PTF_PATH) clean
	$(MAKE) -C $(LIB_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PTF_PATH) fclean
	$(MAKE) -C $(LIB_PATH) fclean
	$(MAKE) -C $(MLX_PATH) clean

re: fclean all

.PHONY: all clean fclean re