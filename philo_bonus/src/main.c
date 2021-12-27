/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galetha <galetha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:03:33 by galetha           #+#    #+#             */
/*   Updated: 2021/12/27 12:28:12 by galetha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	ft_clear(t_qw **qw)
{
	free((*qw)->ptr);
	free (*qw);
	sem_unlink("/forkk");
	sem_unlink("/print");
	sem_unlink("/died");
	sem_close((*qw)->forks);
	sem_close((*qw)->print);
	sem_close((*qw)->died);
}

int	main(int ac, char **av)
{
	t_qw	*qw;

	qw = malloc(sizeof(t_qw));
	if (!qw)
		return (-1);
	memset((void *)qw, 0, sizeof(t_qw));
	if (parse_arg(av, ac) == -1)
		p_error('1');
	if (ft_philo_init(ac, av, qw) == -1)
		p_error('2');
	ft_create_process(qw);
	sem_wait(qw->finish);
	if (qw->count != -1)
		printf("All the philosophers ate!\n");
	kill_process(qw);
	ft_clear(&qw);
	return (0);
}
