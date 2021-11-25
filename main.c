#include "philo.h"

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

int ft_check(int ac, char **av)
{
	int i;

	i = 0;
	if (ac != 5)
		return (-1);
	i = ft_atoi(av[1]);
	if (i <= 0)
		return (-1);
	i = ft_atoi(av[2]);
	if (i <= 0)
		return (-1);
	i = ft_atoi(av[3]);
	if (i <= 0)
		return (-1);
	i = ft_atoi(av[4]);
	if (i <= 0)
		return (-1);
	return (0);
}



int monitor(t_g *g)
{
	int i;

	i = 0;
	while (i < g->num_phill)
	{
		if (g->ptr[i].dead == -1)
			return (-1);
		i++;
	}
	return (1);
}


void    *rout(void *k)
{
	t_philo *g;
	
	g = (t_philo *)k;
	if (g->chet == 1)
		usleep(g->eat_time / 2);
	// while (1)
	// {
		ft_forks(g);
		ft_sleep(g);
		ft_think(g);
	// }
	return (NULL);
}

int ft_create_pthread(t_g *g)
{
	g->i = 0;
	while (g->i < g->num_phill)
	{
		if (pthread_create(&g->ptr[g->i].thread, NULL, rout, &g->ptr[g->i]) != 0)
		{
			printf("dont create pthreads\n");
			return (-1);
		}
		g->i++;
	}
	g->j = 0;
	while (g->j < g->num_phill)
	{
		pthread_join(g->ptr[g->j].thread, NULL);
		g->j++;
	}
	return (0);
}

int    ft_start_algo(t_g *g)
{
	g->i = 0;

	if (ft_create_pthread(g) != 0)
	{
		printf("Error in algo\n");
		return (-1);
	}
	while (1)
	{
		if (monitor(g) == -1)
			return (-1);
	}
	return (0);
}

int main(int ac, char **av)
{
	t_g *g;

	g = malloc(sizeof(t_g));
	if (!g)
		return (-1);
	if (ft_check(ac, av) == -1)
	{
		printf("Error args\n");
		return (-1);
	}
	if (start_init(&g, av) == -1)
	{
		printf("Dont allocate memmory\n");
		return (-1);
	}
   if (ft_start_algo(g) == -1)
		return (-1);
	// printf("|%d|\n",ft_get_time(0));
	// ft_time(1);
	return (0);
}