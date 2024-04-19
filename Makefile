RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m

SERVER = server
CLIENT = client

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INCS = minitalk_bonus.h

S_SRCS = server.c
S_OBJ = $(S_SRCS:.c=.o)

C_SRCS = client.c
C_OBJ = $(C_SRCS:.c=.o)

S_BONUS_SRCS = server_bonus.c
S_BONUS_OBJS = $(S_BONUS_SRCS:.c=.o)

C_BONUS_SRCS = client_bonus.c bonus_utils.c
C_BONUS_OBJS = $(C_BONUS_SRCS:.c=.o)

PRINTF = ./printf/libftprintf.a

all: $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	@echo "$(GREEN) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS) \n\n<---------------------------BUILT SUCCESSFULLY!--------------------------->\n"

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)
	@echo "$(GREEN) $(SERVER_BONUS) $(CLIENT_BONUS) \n\n<---------------------------BUILT SUCCESSFULLY!--------------------------->\n"

$(PRINTF):
	@make -C ./printf

$(SERVER): $(S_OBJ) $(PRINTF)
	@echo "$(GREEN)\n<---------------------------BUILDING MANDATORY OBJECTS--------------------------->\n"
	$(CC) $(CFLAGS) $(S_OBJ) $(PRINTF) -o server

$(CLIENT): $(C_OBJ) $(PRINTF)
	@echo "$(GREEN)\n<---------------------------BUILDING MANDATORY OBJECTS--------------------------->\n"
	$(CC) $(CFLAGS) $(C_OBJ) $(PRINTF) -o client

$(SERVER_BONUS): $(S_BONUS_OBJS) $(PRINTF)
	@echo "$(GREEN)\n<---------------------------BUILDING BONUS OBJECTS--------------------------->\n"
	$(CC) $(CFLAGS) $(S_BONUS_OBJS) $(PRINTF) -o server_bonus

$(CLIENT_BONUS): $(C_BONUS_OBJS) $(PRINTF)
	@echo "$(GREEN)\n<---------------------------BUILDING BONUS OBJECTS--------------------------->\n"
	$(CC) $(CFLAGS) $(C_BONUS_OBJS) $(PRINTF) -o client_bonus

%.o: %.c $(INCS)
	@echo "$(YELLOW)\n<---------------------------Compiling--------------------------->"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED) \nCleaning ........................................................................................\n"
	$(MAKE) clean -C ./printf
	$(RM) $(S_OBJ) $(C_OBJ) $(S_BONUS_OBJS) $(C_BONUS_OBJS) $(PRINTF)

fclean: clean
	@echo "$(GREEN)\n<---------------------------All the object files and executables were successfully deleted!--------------------------->\n"
	$(RM) $(CLIENT) $(SERVER) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all
	@echo "$(GREEN)<---------------------------All the object files were deleted and recompiled successfully!--------------------------->\n"

.PHONY: all clean fclean re
