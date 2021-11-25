#ifndef PHILO_H_
# define PHILO_H_

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include "./libft/libft.h"
#include <sys/time.h>


typedef struct s_philo
{
	int				id;
	int				chet;
	int				num_phill;
	int				eat_time;
	int				die_time;
	int				sleep_time;
	int				go_time;
	int				dead;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*print;

}					t_philo;

typedef struct s_g
{
	int				num_phill;
	int				i;
	int				j;
	t_philo			*ptr;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
}					t_g;


int		start_init(t_g **g, char **av);
int		ft_get_time(int time);
int		ft_start_algo(t_g *g);
int		ft_check(int ac, char **av)
int		monitor(t_g *g);
int		ft_create_pthread(t_g *g);
int		ft_atoi(const char *str);
void	*rout(void *k);
void	end_init(t_g **g, int i, char **av);
void	ft_time(int time);
void	ft_think(t_philo *g);
void	main_l(t_philo *g);
void	main_r(t_philo *g);
void    ft_forks(t_philo *g);
void    ft_sleep(t_philo *g);




#endif