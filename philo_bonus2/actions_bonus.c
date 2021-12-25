#include "philo_bonus.h"

void    *ft_monitor(void *arg)
{
    t_phil *ph;
 
    ph = (t_phil *)arg;
    while (1)
    {
        if (ph->num_phil == 1)
        {
            sem_wait(ph->act->died);
            printf(DEAD, ft_get_time() - ph->run_pr, ph->id);
            exit (-1);
        }
        if (ph->last_eat != 0 && ft_get_time() - ph->last_eat > ph->live_time)
        {
            sem_wait(ph->act->died);
            printf(DEAD, ft_get_time() - ph->run_pr, ph->id);
            exit (0);
        }
    }
    return (NULL);
}

void    eat(t_phil *ph)
{
    sem_wait(ph->act->forks);
    sem_wait(ph->act->print);
    printf(R_FORK, ft_get_time() - ph->run_pr, ph->id);
    sem_post(ph->act->print);
    sem_post(ph->act->print);
    sem_wait(ph->act->forks);
    printf(L_FORK, ft_get_time() - ph->run_pr, ph->id);
    sem_post(ph->act->print);
    sem_wait(ph->act->print);
    printf(EAT, ft_get_time() - ph->run_pr, ph->id);
    sem_post(ph->act->print);
    ph->last_eat = ft_get_time();
    ft_time(ph->eat_time);
    if (ph->count_eat > 0)
        ph->count_eat--;
    if (ph->count_eat == 0)
        ph->act->count--;
    sem_post(ph->act->forks);
    sem_post(ph->act->forks);
}

void    sleep_think(t_phil *ph)
{
    sem_wait(ph->act->print);
    printf(SLEEP, ft_get_time() - ph->run_pr, ph->id);
    sem_post(ph->act->print);
    ft_time(ph->sleep_time);
    sem_wait(ph->act->print);
    printf(THINK, ft_get_time() - ph->run_pr, ph->id);
    sem_post(ph->act->print);
}

void    ft_process(t_phil *ph)
{
    pthread_t monitoring;

    if (ph->chet == 1)
        usleep(ph->eat_time / 2);
    pthread_create(&monitoring, NULL, ft_monitor, ph);
    while (ph->act->count != 0)
    {
        eat(ph);
        sleep_think(ph);
    }
    exit (-1);
}

void    ft_create_process(t_qw *qw)
{
    int i;

    i = 0;
    qw->run_pr = ft_get_time();
    while (i < qw->num_phil)
    {
        qw->ptr[i].run_pr = qw->run_pr;
        qw->ptr[i].last_eat = qw->ptr[i].run_pr;
        qw->ptr[i].pid = fork();
        if (qw->ptr[i].pid == 0)
            ft_process(&qw->ptr[i]);
        else if (qw->ptr[i].pid < 0)
            exit (0);
        i++;
    }
}
