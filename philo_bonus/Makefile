NAME = philo_bonus

FLAGS = -I./includes -Wall -Wextra -Werror

SRC = ./src/main.c\
		./src/actions_bonus.c\
		./src/init_bonus.c\
		./src/time.c\
		./src/utils_bonus.c\

OBJ = $(patsubst %.c,%.o,$(SRC))

all :
	@make $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

%.o : %.c includes
	gcc $(FLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re