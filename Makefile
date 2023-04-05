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

NAME = ft_printf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -rf
CFILES = ft_format_check ft_print_hex ft_print_nbr ft_print_ptr ft_printf ft_utils
CFILES_B = ft_format_check_bonus ft_format_check_bonus1 ft_print_hex_bonus ft_print_int_bonus ft_print_ptr_bonus ft_print_uint_bonus ft_printf_bonus ft_utils_bonus ft_utils_bonus1

SRCS = $(addprefix $(SRCSDIR), $(addsuffix .c, $(CFILES)))
BONUS = $(addprefix $(BONUSDIR), $(addsuffix .c, $(CFILES_B)))
SRCSDIR = srcs/
BONUSDIR = bonus/
OBJS = $(SRCS:.c=.o)
OBJS_B = $(BONUS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJS_B)
	$(AR) $(NAME) $(OBJS) $(OBJS_B)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = re all clean fclean bonus
