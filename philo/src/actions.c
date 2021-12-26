/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galetha <galetha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:06:27 by galetha           #+#    #+#             */
/*   Updated: 2021/12/26 14:23:14 by galetha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	catch_forks(t_philo *g)
{
	catch_r(g);
	catch_l(g);
	pthread_mutex_lock(g->print);
	printf(EAT, ft_get_time() - g->run_pr, g->id);
	pthread_mutex_unlock(g->print);
	g->last_eat = ft_get_time();
	ft_time(g->eat_time);
	pthread_mutex_unlock(g->l_fork);
	pthread_mutex_unlock(g->r_fork);
	if (g->count_eat != -1 && g->count_eat > 0)
		g->count_eat--;
}

void	sleep_phil(t_philo *g)
{
	pthread_mutex_lock(g->print);
	printf(SLEEP, ft_get_time() - g->run_pr, g->id);
	pthread_mutex_unlock(g->print);
	ft_time(g->sleep_time);
}

void	think_phil(t_philo *g)
{
	pthread_mutex_lock(g->print);
	printf(THINK, ft_get_time() - g->run_pr, g->id);
	pthread_mutex_unlock(g->print);
}

void	ft_die(t_g *g, int i)
{
	pthread_mutex_lock(&g->print);
	printf(DEAD, ft_get_time() - g->ptr[i].run_pr, g->ptr[i].id);
	usleep(100);
}
