NAME = philo_bonus

SRC =	./src/main.c\
	 	./src/init_bonus.c\
		./src/actions_bonus.c\
		./src/time.c\
		./src/utils_bonus.c\

HEADER = philo.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

%.o: %.c		$(HEADER)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean: 
	@rm -f *.o

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re 