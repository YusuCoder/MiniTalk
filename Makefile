RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = 

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
