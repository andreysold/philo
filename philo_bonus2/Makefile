NAME = philo_bonus

SRC = main.c init_bonus.c	actions_bonus.c time.c utils_bonus.c

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