#include "philo.h"


int ft_get_time(int time)
{
	struct timeval	x;
	int				t;

	(void )time;
	t = 0;
	gettimeofday(&x, NULL);
	t = (x.tv_sec * 1000) + (x.tv_usec / 1000);
	return (t);
}

void    ft_time(int time)
{
	int	t;

	t = 0;
	t = ft_get_time(time);
	while (ft_get_time(0) - t < time)
		usleep(100);
}