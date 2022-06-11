NAME = 	philo_bonus
SRC	 = $(shell find . -name "*.c")
OBJ  = $(SRC:.c=.o)
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ)
	gcc -pthread $(FLAG) $(OBJ) -o $(NAME)

fclean:
	@rm -rf $(NAME)
	@rm -rf $(OBJ)
clean:
	@rm -rf $(OBJ)
re: fclean all