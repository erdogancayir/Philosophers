CC		=	gcc
NAME 	=	philo
SRC		=	create.c utils_libft.c utils_1.c init.c main.c die.c
OBJ		= 	$(SRC:.c=.o)
FLAGS	=	-Wall -Werror -Wextra
BLUE = \033[1;34m

all: $(NAME) credit
	@echo "$(BLUE)██████████████████████ Compiling is DONE ███████████████████████$(RESET)"

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o philo
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(OBJ)
re: fclean all
.PHONY: clean fclean re all
credit:
	@echo "\033[1;33m▀██▀▀█▄  ▀██       ██  ▀██                                  ▀██"
	@echo "\033[1;33m ██   ██  ██ ▄▄   ▄▄▄   ██    ▄▄▄    ▄▄▄▄    ▄▄▄   ▄▄▄ ▄▄▄   ██ ▄▄     ▄▄▄▄  ▄▄▄ ▄▄   ▄▄▄▄"
	@echo "\033[1;33m ██▄▄▄█▀  ██▀ ██   ██   ██  ▄█  ▀█▄ ██▄ ▀  ▄█  ▀█▄  ██▀  ██  ██▀ ██  ▄█▄▄▄██  ██▀ ▀▀ ██▄ ▀"
	@echo "\033[1;33m ██       ██  ██   ██   ██  ██   ██ ▄ ▀█▄▄ ██   ██  ██    █  ██  ██  ██       ██     ▄ ▀█▄▄"
	@echo "\033[1;33m▄██▄     ▄██▄ ██▄ ▄██▄ ▄██▄  ▀█▄▄█▀ █▀▄▄█▀  ▀█▄▄█▀  ██▄▄▄▀  ▄██▄ ██▄  ▀█▄▄▄▀ ▄██▄    █▀▄▄█▀"
	@echo "\033[1;33m                                                    ██"
	@echo "\033[1;35m         Made with love by : \033[1;95mecayir\033[1;33m                 ▀▀▀▀"