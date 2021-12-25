#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H





#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>
#include <limits.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#define DEAD	"%dms %3.d has dead\n"
#define EAT 	"%dms %3.d has eating\n"
#define L_FORK	"%dms %3.d has taken a fork\n"
#define R_FORK	"%dms %3.d has taken a fork\n"
#define SLEEP	"%dms %3.d has sleeping\n"
#define THINK	"%dms %3.d has thinking\n"

typedef struct 		s_phil
{
	int 			id;
	pid_t 			pid;
	int 			chet;
	int 			num_phil;
	int 			live_time;
	int 			eat_time;
	int 			sleep_time;
	int 			count_eat;
	int 			last_eat;
	int 			run_pr;
	struct s_qw 	*act;
	int				dead;
}   				t_phil;

typedef struct 	s_qw
{
	int			num_phil;
	int			run_pr;
	int			count;
	int         dead;
	int    		i;
	int     	j;
	sem_t   	*forks;
	sem_t   	*print;
	sem_t       *died;
	sem_t		*finish;
	t_phil      *ptr;

}   			t_qw;


void    ft_time(int time);
void	p_error(char c);
void	ft_end_init(int ac, char **av, t_qw *qw, int i);
void    ft_create_process(t_qw *qw);
void    *ft_process(t_phil *ph);
void    kill_process(t_qw *g);
void    sleep_think(t_phil *ph);
void    eat(t_phil *ph);
void    *ft_monitor(void *arg);
int		check_count_eat(t_qw *f);
int		ft_get_time(void);
int		ft_atoi(const char *str);
int		parse_arg(char **av, int ac);
int		ft_philo_init(int ac, char **av, t_qw *qw);

#endif