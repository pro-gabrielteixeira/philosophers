GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = philo
CC = cc -pthread
FLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
#valgrind --leak-check=full --show-leak-kinds=all
OBJ = $(patsubst src%, obj%, $(SRC:.c=.o))
SRC = src/philosophers.c src/utils.c src/routine.c src/threads.c

all: obj $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $@ $^

obj:
	@mkdir -p obj

obj/%.o: src/%.c
	@echo "$@ $(GREEN)created$(RESET)"
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ) obj
	@echo "Object files removed."

fclean: clean
	@rm -rf $(NAME)
	@echo "Binary file removed."

re: fclean all

.PHONY: all clean fclean re