#include "philo.h"

void	ft_init_forks(t_g *g, int i)
{
	if (g->ptr[i].chet == 1)
	{
		g->ptr[i].l_fork = &g->forks[i];
		g->ptr[i].r_fork = &g->forks[(i + 1) % g->num_phill];
	}
	else
	{
		g->ptr[i].r_fork = &g->forks[i];
		g->ptr[i].l_fork = &g->forks[(i + 1) % g->num_phill];
	}
}
void    phil_init2(t_g *g, char **av, int i, int ac)
{
	g->ptr[i].id = i + 1;
	g->ptr[i].num_phill = ft_atoi(av[1]);
	if (g->ptr[i].id % 2 != 0)
		g->ptr[i].chet = 1;
	else
		g->ptr[i].chet = 0;
	g->ptr[i].die_time = ft_atoi(av[2]);
	g->ptr[i].eat_time = ft_atoi(av[3]);
	g->ptr[i].sleep_time = ft_atoi(av[4]);
	g->ptr[i].last_eat = 0;
	if (ac == 6)
		g->ptr[i].count_eat = ft_atoi(av[5]);
	else
		g->ptr[i].count_eat = -1;
	ft_init_forks(g, i);
	g->ptr[i].dead = 0;
	g->ptr[i].run_pr = 0;
	g->ptr[i].print = &g->print;
}

int    phil_init(t_g *g, char **av, int ac)
{
	int i;

	i = 0;
	g->num_phill = ft_atoi(av[1]);
	if (ac == 6)
		g->count_eat = ft_atoi(av[5]);
	g->ptr = (t_philo *)malloc(sizeof(t_philo) * g->num_phill);
	if (!(g->ptr))
		return (-1);
	g->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * g->num_phill);
	if (!(g->forks))
		return (-1);
	while (i < g->num_phill)
		pthread_mutex_init(&g->forks[i++], NULL);
	pthread_mutex_init(&g->print, NULL);
	i = 0;
	while (i < g->num_phill)
	{
		phil_init2(g, av, i, ac);
		i++;
	}
	return (0);
}

int    parse_arg(char **av, int ac)
{
	int i;

	i = 0;
	if (!(ac == 5 || ac == 6))
		return (-1);
	i = ft_atoi(av[1]);
	if (i <= 0 || i > 200)
		return (-1);
	i = ft_atoi(av[2]);
	if (i <= 0 || i < 60)
		return (-1);
	i = ft_atoi(av[3]);
	if (i <= 0 || i < 60)
		return (-1);
	i = ft_atoi(av[4]);
	if (i <= 0 || i < 60)
		return (-1);
	if (ac == 6)
		i = ft_atoi(av[5]);
	if (i <= 0)
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				min;
	unsigned int	res;
	char			*p;

	p = (char *) str;
	i = 0;
	min = 1;
	res = 0;
	while ((p[i] >= 0x09 && p[i] <= 0x0D) || (p[i] == ' '))
		i++;
	if (p[i] == '-')
		min *= -1;
	if (p[i] == '-' || p[i] == '+')
		i++;
	while (p[i] >= '0' && p[i] <= '9')
	{
		res = (res * 10) + (p[i] - '0');
		i++;
	}
	if (res > 2147483648 && min == -1)
		return (0);
	if (res > INT_MAX && min == 1)
		return (-1);
	return (min * res);
}