RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client

S_SRCS = server.c
S_OBJ = $(S_SRCS:.c=.o)

C_SRCS = clinet.c
C_OBJ = $(C_SRCS:.c=.o)

PRINTF = ./printf/printf.a
PATH_PRINTF = ./printf

INCS = ./printf/ft_printf.h
RM = rm -f

all: $(SERVER) $(CLIENT)
	@echo "$(GREEN)$(SERVER) $(CLIENT) \n\n<---------------------------BUILT SUCCESSFULLY!--------------------------->\n"

$(SERVER): $(S_OBJ)
	@echo "$(GREEN)\n<---------------------------BUILDING MANDATORY OBJECTS--------------------------->\n"
	$(CC) $(CFLAGS) -o $(SERVER) $(S_OBJ)

$(CLIENT): $(C_OBJ)
	@echo "$(GREEN)\n<---------------------------BUILDING MANDATORY OBJECTS--------------------------->\n"
	$(CC) $(CFLAGS) -o $(CLIENT) $(C_OBJ)

$(PRINTF):
	@make -C $(PATH_PRINTF)

%.o: %.c $(INCS)
	@echo "$(YELLOW)\n<---------------------------Compiling--------------------------->"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED) \nCleaning ........................................................................................\n"
	$(RM) $(S_OBJ) $(C_OBJ) $(SERVER) $(CLIENT)

fclean: clean
	@echo "$(GREEN)\n<---------------------------All the object files and executables were successfully deleted!--------------------------->\n"

re: fclean all
	@echo "$(GREEN)<---------------------------All the object files were deleted and recompiled successfully!--------------------------->\n"

.PHONY: all clean fclean re
