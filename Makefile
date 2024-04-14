RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m

SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

S_SRCS = server.c
S_OBJ = $(S_SRCS:.c=.o)

C_SRCS = client.c
C_OBJ = $(C_SRCS:.c=.o)

PRINTF = ./printf/libftprintf.a

all: $(SERVER) $(CLIENT)
	@echo "$(GREEN) $(SERVER) $(CLIENT) \n\n<---------------------------BUILT SUCCESSFULLY!--------------------------->\n"

$(PRINTF):
	@make -C ./printf

$(SERVER): $(S_OBJ) $(PRINTF)
	@echo "$(GREEN)\n<---------------------------BUILDING MANDATORY OBJECTS--------------------------->\n"
	$(CC) $(CFLAGS) $(S_OBJ) $(PRINTF) -o server

$(CLIENT): $(C_OBJ) $(PRINTF)
	@echo "$(GREEN)\n<---------------------------BUILDING MANDATORY OBJECTS--------------------------->\n"
	$(CC) $(CFLAGS) $(C_OBJ) $(PRINTF) -o client

%.o: %.c
	@echo "$(YELLOW)\n<---------------------------Compiling--------------------------->"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED) \nCleaning ........................................................................................\n"
	$(MAKE) clean -C ./printf
	$(RM) $(S_OBJ) $(C_OBJ) $(PRINTF)

fclean: clean
	@echo "$(GREEN)\n<---------------------------All the object files and executables were successfully deleted!--------------------------->\n"
	$(RM) $(CLIENT) $(SERVER)

re: fclean all
	@echo "$(GREEN)<---------------------------All the object files were deleted and recompiled successfully!--------------------------->\n"

.PHONY: all clean fclean re
