/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   times.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galetha <galetha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:06:55 by galetha           #+#    #+#             */
/*   Updated: 2021/12/26 14:35:26 by galetha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_get_time(void)
{
	struct timeval	x;
	int				t;

	t = 0;
	gettimeofday(&x, NULL);
	t = (x.tv_sec * 1000) + (x.tv_usec / 1000);
	return (t);
}

void	ft_time(int time)
{
	long long	cur;
	long long	res;

	res = 0;
	cur = ft_get_time();
	res = cur + time;
	while (cur < res)
	{
		usleep(100);
		cur = ft_get_time();
	}
}

void	p_error(char c)
{
	if (c == '1')
		printf("Incorrect args\n");
	else if (c == '2')
		printf("Dont allocate memmory");
	exit (-1);
}

void	catch_r(t_philo	*g)
{
	pthread_mutex_lock(g->r_fork);
	pthread_mutex_lock(g->print);
	printf(R_FORK, ft_get_time() - g->run_pr, g->id);
	pthread_mutex_unlock(g->print);
}

void	catch_l(t_philo *g)
{
	pthread_mutex_lock(g->l_fork);
	pthread_mutex_lock(g->print);
	printf(L_FORK, ft_get_time() - g->run_pr, g->id);
	pthread_mutex_unlock(g->print);
}
