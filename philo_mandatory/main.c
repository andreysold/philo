#include "philo.h"


int create_thread(t_g *g)
{
    g->j = 0;
    while (g->j < g->num_phill)
    {
        g->ptr[g->j].run_pr = ft_get_time();
        if (pthread_create(&g->ptr[g->j].thread, NULL, process, &g->ptr[g->j]) != 0)
        {
            printf("Dont create thread!\n");
            ft_clear(&g);
            return (-1);
        }
        pthread_detach(g->ptr[g->j].thread);
        g->j++;
    }
    return (0);
}
int main(int ac, char **av)
{
    t_g *g;

    g = malloc(sizeof(t_g));
    if (!g)
        return (-1);
    if (parse_arg(av, ac) == -1)
    {
        p_error('1');
        free (g);
        return (-1);
    }
    if (phil_init(g, av, ac) == -1)
    {
        p_error('2');
        free (g);
        return (-1);
    }
    create_thread(g);
    if (waiter(g) == 0)
       ft_clear(&g);
    return (0);
}