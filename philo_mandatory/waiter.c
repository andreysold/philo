#include "philo.h"

void    *process(void *arg)
{
    t_philo *g;

    g = (t_philo *)arg;
    while (g->dead == 0)
    {
        catch_forks(g);
        sleep_phil(g);
        think_phil(g);
    }
    return (NULL);
}

int check_count_eat(t_g *f)
{
    int count;
    int i;

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

void    ft_end(t_g *g)
{
    int i;

    i = 0;
    while (i < g->num_phill)
        pthread_mutex_destroy(&g->forks[i++]);
    pthread_mutex_destroy(&g->print);
}

int waiter(t_g *f)
{
    int time;

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
            if (time - f->ptr[f->i].last_eat > f->ptr[f->i].die_time && f->ptr[f->i].last_eat != 0)
            {
                ft_die(f, f->i);
                f->ptr[f->i].dead = -1;
                return (0);
            }
            else if (check_count_eat(f) == 1)
            {
                pthread_mutex_lock(&f->print);
                printf("All was eating!\n");
                return (0);
            }
            f->i++;
        }
    }
    return (0);
}

void    ft_clear(t_g **g)
{
    ft_end(*g);
    if ((*g)->ptr)
    {
        free ((*g)->ptr);
        (*g)->ptr = NULL;
    }
    if ((*g)->forks)
    {
        free ((*g)->forks);
        (*g)->forks = NULL;
    }
    free ((*g));
}