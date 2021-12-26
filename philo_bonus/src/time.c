/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galetha <galetha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:05:11 by galetha           #+#    #+#             */
/*   Updated: 2021/12/26 15:12:25 by galetha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
