#include "philo.h"

typedef struct s_philo
{
    int id;
    int chet;
    int eat_time;
    int die_time;
    int sleep_time;
    int go_time;
    pthread_t thread;
    pthread_mutex_t *l_fork;
    pthread_mutex_t *r_fork;
    pthread_mutex_t *print;

}   t_philo;

typedef struct s_g
{
    int num_phill;
    int i;
    int j;
    t_philo *ptr;
    pthread_mutex_t print;
    pthread_mutex_t *forks;
}   t_g;

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

void    end_init(t_g **g, int i, char **av)
{
    (*g)->ptr[i].id = i + 1; 
    if ((*g)->ptr[i].id % 2 != 0)
        (*g)->ptr[i].chet = 1;
    else
        (*g)->ptr[i].chet = 0;
    (*g)->ptr[i].die_time = ft_atoi(av[2]);
    (*g)->ptr[i].eat_time = ft_atoi(av[3]);
    (*g)->ptr[i].sleep_time = ft_atoi(av[4]);
    (*g)->ptr[i].go_time = 0;
    (*g)->ptr[i].l_fork = &(*g)->forks[i];
    (*g)->ptr[i].r_fork = &(*g)->forks[(i + 1) % (*g)->num_phill];
    (*g)->ptr[i].print = &(*g)->print;
}

int    start_init(t_g **g, char **av)
{
    (*g)->num_phill = ft_atoi(av[1]);
    (*g)->ptr = (t_philo *)malloc(sizeof(t_philo) * (*g)->num_phill);
    if (!(*g)->ptr)
        return (-1);
    (*g)->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (*g)->num_phill);
    if (!(*g)->forks)
        return (-1);
    (*g)->i = 0;
    while ((*g)->i < (*g)->num_phill)
    {
        pthread_mutex_init(&(*g)->forks[(*g)->i], NULL);
        (*g)->i++;
    }
    pthread_mutex_init(&(*g)->print, NULL);
    (*g)->i = 0;
    while ((*g)->i < (*g)->num_phill)
    {
        end_init(g, (*g)->i, av);
        (*g)->i++;
    }
    (*g)->j = 0;
    return (0);
}

void    ft_think(t_philo *g)
{
    pthread_mutex_lock(g->print);
    printf("Philos %d think\n", g->id);
    pthread_mutex_unlock(g->print);
}

void    ft_forks(t_philo *g)
{
    if (g->chet == 1)
    {
        pthread_mutex_lock(g->l_fork);
        pthread_mutex_lock(g->print);
        printf("philos | %d | has taken a fork (l)\n", g->id);
        pthread_mutex_unlock(g->print);
    }
    else
    {
        pthread_mutex_lock(g->r_fork);
        pthread_mutex_lock(g->print);
        printf("philos | %d | has taken a fork (r)\n", g->id);
        pthread_mutex_unlock(g->print);
    }
    pthread_mutex_unlock(g->print);
    if (g->chet == 1)
    {
        pthread_mutex_lock(g->r_fork);
        pthread_mutex_lock(g->print);
        printf("philos | %d | has taken a fork (r)\n", g->id);
    }
    else
    {
        pthread_mutex_lock(g->l_fork);
        pthread_mutex_lock(g->print);
        printf("philos | %d | has taken a fork (l)\n", g->id);
    }
    pthread_mutex_unlock(g->print);
    pthread_mutex_unlock(g->r_fork);
    pthread_mutex_unlock(g->l_fork);
}

void    ft_sleep(t_philo *g)
{
    pthread_mutex_lock(g->print);
    printf("Philos %d sleep\n", g->id);
    pthread_mutex_unlock(g->print);
}

void    *rout(void *k)
{
    t_philo *g;
    
    g = (t_philo *)k;
    if (g->chet == 1)
        usleep(g->eat_time / 2);
    while (1)
    {
        ft_forks(g);
        ft_sleep(g);
        ft_think(g);
    }
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
    return (0);
}