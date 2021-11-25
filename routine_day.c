#include <philo.h>


void    ft_think(t_philo *g)
{
	pthread_mutex_lock(g->print);
	printf("Philos %d think\n", g->id);
	pthread_mutex_unlock(g->print);
}


void	main_l(t_philo *g)
{
	pthread_mutex_lock(g->l_fork);
	pthread_mutex_lock(g->print);
	printf("philos | %d | has taken a fork (l)\n", g->id);
	pthread_mutex_unlock(g->print);
}

void	main_r(t_philo *g)
{
	pthread_mutex_lock(g->r_fork);
	pthread_mutex_lock(g->print);
	printf("philos | %d | has taken a fork (r)\n", g->id);
	pthread_mutex_unlock(g->print);
}

void    ft_forks(t_philo *g)
{
	if (g->chet == 1)
	{
		// pthread_mutex_lock(g->l_fork);
		// pthread_mutex_lock(g->print);
		// printf("philos | %d | has taken a fork (l)\n", g->id);
		// pthread_mutex_unlock(g->print);
		main_l(g);
	}
	else
	{
		// pthread_mutex_lock(g->r_fork);
		// pthread_mutex_lock(g->print);
		// printf("philos | %d | has taken a fork (r)\n", g->id);
		// pthread_mutex_unlock(g->print);
		main_r(g);
	}
	if (g->chet == 1)
	{
		// pthread_mutex_lock(g->r_fork);
		// pthread_mutex_lock(g->print);
		// printf("philos | %d | has taken a fork (r)\n", g->id);
		main_r(g);
	}
	else
	{
		// pthread_mutex_lock(g->l_fork);
		// pthread_mutex_lock(g->print);
		// printf("philos | %d | has taken a fork (l)\n", g->id);
		main_l(g);
	}
	pthread_mutex_unlock(g->r_fork);
	pthread_mutex_unlock(g->l_fork);
}

void    ft_sleep(t_philo *g)
{
	pthread_mutex_lock(g->print);
	printf("Philos %d sleep\n", g->id);
	pthread_mutex_unlock(g->print);
}