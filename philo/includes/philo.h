/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galetha <galetha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:39:43 by galetha           #+#    #+#             */
/*   Updated: 2021/12/26 14:40:22 by galetha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include "limits.h"
# include <string.h>

# define DEAD	"%lldms %3.d \033[1;31mhas dead\x1b[0m\n"
# define EAT 	"%lldms %3.d \033[0;32mhas eating\x1b[0m\n"
# define L_FORK	"%lldms %3.d \033[1;33mhas taken a fork (l)\x1b[0m\n"
# define R_FORK	"%lldms %3.d \033[1;33mhas taken a fork (r)\x1b[0m\n"
# define SLEEP	"%lldms %3.d \033[0;35mhas sleeping\x1b[0m\n"
# define THINK	"%lldms %3.d \033[0;34mhas thinking\x1b[0m\n"

typedef struct s_philo
{
	int				id;
	int				chet;
	int				num_phill;
	int				eat_time;
	int				die_time;
	int				sleep_time;
	long long		last_eat;
	int				dead;
	long long		run_pr;
	int				count_eat;
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
	int				run_pr;
	int				count_eat;
	int				g_dead;
	t_philo			*ptr;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;

}					t_g;

void	ft_die(t_g *g, int i);
void	think_phil(t_philo *g);
void	sleep_phil(t_philo *g);
void	catch_forks(t_philo *g);
void	*process(void *arg);
void	ft_end(t_g *g);
void	phil_init2(t_g *g, char **av, int i, int ac);
void	ft_time(int time);
void	catch_r(t_philo *g);
void	catch_l(t_philo *g);
void	ft_clear(t_g **g);
void	ft_init_forks(t_g *g, int i);
void	p_error(char c);
int		check_count_eat(t_g *f);
int		waiter(t_g *f);
int		phil_init(t_g *g, char **av, int ac);
int		parse_arg(char **av, int ac);
int		ft_atoi(const char *str);
int		ft_get_time(void);
int		create_thread(t_g *g);

#endif