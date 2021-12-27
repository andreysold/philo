NAME = philo

FLAGS = -I./includes -Wall -Wextra -Werror

SRC = ./src/philo.c\
		./src/actions.c\
		./src/init.c\
		./src/times.c\
		./src/waiter.c\

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