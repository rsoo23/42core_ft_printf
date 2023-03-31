# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 12:08:43 by rsoo              #+#    #+#              #
#    Updated: 2023/03/27 12:08:43 by rsoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
AR = ar rcs
RM = rm -rf
CFILES = ft_printf.c ft_print_hex.c ft_print_nbr.c ft_print_ptr.c \
ft_print_utils.c

OBJS = $(CFILES:.c=.o)

$(OBJS): $(CFILES)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
