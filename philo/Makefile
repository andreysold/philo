NAME = philo

SRC = 	./src/main.c\
	 	./src/init.c\
		./src/actions.c\
		./src/times.c\
		./src/waiter.c\

HEADER = philo.h

CC = gcc

FLAGS = -Wall -Wextra -Werror 

all : $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

%.o: %.		$(HEADER)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean: 
	@rm -f *.o

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re 