# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bloisel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 13:29:34 by bloisel           #+#    #+#              #
#    Updated: 2022/12/09 16:25:04 by bloisel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=   libftprintf.a
SRCS	=	ft_printf.c \
			ft_putchar.c \
			ft_putnbr_base.c \
			ft_putnbr_base2.c \
			ft_putnbr_unsigned.c \
			ft_putnbr.c \
			ft_putstr.c \
			ft_strlen.c \


OBJS	= $(SRCS:.c=.o)
RM	= rm -f
LIBC	= ar -rcs
FLAGS	= -Wall -Wextra -Werror
INCS	= .

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

$(NAME): ${OBJS}
	${LIBC} $(NAME) $(OBJS)

all: $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) -f $(OBJS)

re: fclean all

.PHONY: clean fclean re .c.o
