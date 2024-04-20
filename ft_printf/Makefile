# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 14:16:36 by ryusupov          #+#    #+#              #
#    Updated: 2024/04/14 14:01:40 by ryusupov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putnbr.c ft_ishex.c ft_decimal.c ft_print_adress.c ft_putchar.c ft_putstr.c ft_strlen.c

OBJ = $(SRC:.c=.o)

AR = ar rcs
INCS = ft_printf.h
RM = rm -f

all: $(NAME)
	@echo "$(GREEN)$(NAME) \n\n<---------------------------BUILT SUCCESSFULLY!--------------------------->\n"

$(NAME): $(OBJ)
	@echo "$(GREEN)\n<---------------------------BUILDING MANDATORY OBJECTS--------------------------->\n"
	$(AR) $(NAME) $(OBJ)

%.o: %.c $(INCS)
	@echo "$(YELLOW)\n<---------------------------Compiling--------------------------->"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED) \nCleaning ........................................................................................\n"
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	@echo "$(GREEN)\n<---------------------------All the object files was successfully deleted!--------------------------->\n"

re: fclean all
	@echo "$(GREEN)<---------------------------All the object files was deleted and recompiled successfully!--------------------------->\n"

.PHONY: all clean fclean re
