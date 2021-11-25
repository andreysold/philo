#include "philo.h"

void    end_init(t_g **g, int i, char **av)
{
	(*g)->ptr[i].id = i + 1; 
	if ((*g)->ptr[i].id % 2 != 0)
		(*g)->ptr[i].chet = 1;
	else
		(*g)->ptr[i].chet = 0;
	(*g)->ptr[i].die_time = ft_atoi(av[2]);
	(*g)->ptr[i].eat_time = ft_atoi(av[3]);
	(*g)->ptr[i].sleep_time = ft_atoi(av[4]);
	(*g)->ptr[i].go_time = 0;
	(*g)->ptr[i].l_fork = &(*g)->forks[i];
	(*g)->ptr[i].r_fork = &(*g)->forks[(i + 1) % (*g)->num_phill];
	(*g)->ptr[i].print = &(*g)->print;
	(*g)->ptr[i].dead = 1;
	(*g)->ptr[i].num_phill = ft_atoi(av[1]);
}

int    start_init(t_g **g, char **av)
{
	(*g)->num_phill = ft_atoi(av[1]);
	(*g)->ptr = (t_philo *)malloc(sizeof(t_philo) * (*g)->num_phill);
	if (!(*g)->ptr)
		return (-1);
	(*g)->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (*g)->num_phill);
	if (!(*g)->forks)
		return (-1);
	(*g)->i = 0;
	while ((*g)->i < (*g)->num_phill)
	{
		pthread_mutex_init(&(*g)->forks[(*g)->i], NULL);
		(*g)->i++;
	}
	pthread_mutex_init(&(*g)->print, NULL);
	(*g)->i = 0;
	while ((*g)->i < (*g)->num_phill)
	{
		end_init(g, (*g)->i, av);
		(*g)->i++;
	}
	(*g)->j = 0;
	return (0);
}