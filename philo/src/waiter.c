/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galetha <galetha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:07:03 by galetha           #+#    #+#             */
/*   Updated: 2021/12/27 12:03:02 by galetha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_count_eat(t_g *f)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < f->num_phill)
	{
		if (f->ptr[i].count_eat == 0)
			count++;
		i++;
	}
	if (count == f->num_phill)
		return (1);
	return (0);
}

void	ft_end(t_g *g)
{
	int	i;

	i = 0;
	while (i < g->num_phill)
	{
		pthread_mutex_destroy(&g->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&g->print);
}

int	cond_waiter(t_g *f, int i, int time)
{
	if (time - f->ptr[i].last_eat > f->ptr[i].die_time
		&& f->ptr[i].last_eat != 0)
	{
		ft_die(f, i);
		f->ptr[i].dead = -1;
		return (1);
	}
	else if (check_count_eat(f) == 1)
	{
		pthread_mutex_lock(&f->print);
		printf("All the philosophers ate!\n");
		return (1);
	}
	return (0);
}

int	waiter(t_g *f)
{
	int	time;

	time = 0;
	while (1)
	{
		f->i = 0;
		time = ft_get_time();
		while (f->i < f->num_phill)
		{
			if (f->num_phill == 1)
			{
				ft_time(f->ptr[f->i].die_time + 1);
				ft_die(f, f->i);
				return (0);
			}
			if (cond_waiter(f, f->i, time) == 1)
				return (0);
			f->i++;
		}
	}
	return (0);
}

void	ft_clear(t_g **g)
{
	ft_end(*g);
	if ((*g)->ptr)
	{
		free ((*g)->ptr);
		(*g)->ptr = NULL;
	}
	if ((*g)->forks)
	{
		free((*g)->forks);
		(*g)->forks = NULL;
	}
	free((*g));
}
