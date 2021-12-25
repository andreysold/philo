#include "philo_bonus.h"


int	ft_atoi(const char *str)
{
    int				i;
    int				min;
    unsigned int	res;
    char			*p;

    p = (char *) str;
    i = 0;
    min = 1;
    res = 0;
    while ((p[i] >= 0x09 && p[i] <= 0x0D) || (p[i] == ' '))
        i++;
    if (p[i] == '-')
        min *= -1;
    if (p[i] == '-' || p[i] == '+')
        i++;
    while (p[i] >= '0' && p[i] <= '9')
    {
        res = (res * 10) + (p[i] - '0');
        i++;
    }
    if (res > 2147483648 && min == -1)
        return (0);
    if (res > INT_MAX && min == 1)
        return (-1);
    return (min * res);
}


int    parse_arg(char **av, int ac)
{
    int i;

    i = 0;
    if (!(ac == 5 || ac == 6))
        return (-1);
    i = ft_atoi(av[1]);
    if (i <= 0 || i > 200)
        return (-1);
    i = ft_atoi(av[2]);
    if (i <= 0 || i < 60)
        return (-1);
    i = ft_atoi(av[3]);
    if (i <= 0 || i < 60)
        return (-1);
    i = ft_atoi(av[4]);
    if (i <= 0 || i < 60)
        return (-1);
    if (ac == 6)
        i = ft_atoi(av[5]);
    if (i <= 0)
        return (-1);
    return (1);
}

void    ft_end_init(int ac, char **av, t_qw *qw, int i)
{
    qw->ptr[i].id = i + 1;
    if (qw->ptr[i].id % 2 != 0)
        qw->ptr[i].chet = 0;
    else
        qw->ptr[i].chet = 1;
    qw->ptr[i].live_time = ft_atoi(av[2]);
    qw->ptr[i].eat_time = ft_atoi(av[3]);
    qw->ptr[i].sleep_time = ft_atoi(av[4]);
    if (ac == 6)
        qw->ptr[i].count_eat = ft_atoi(av[5]);
    else
        qw->ptr[i].count_eat = -1;
    qw->ptr[i].last_eat = 0;
    qw->ptr[i].run_pr = 0;
    qw->ptr[i].act = qw;

}
int ft_philo_init(int ac, char **av, t_qw *qw)
{
    qw->num_phil = ft_atoi(av[1]);
    qw->ptr = (t_phil *)malloc(sizeof(t_phil) * qw->num_phil);
    sem_unlink("/forkk");
    qw->forks = sem_open("/forkk", O_CREAT | O_EXCL, S_IRWXU, qw->num_phil);
    sem_unlink("/print");
    qw->print = sem_open("/print", O_CREAT | O_EXCL, S_IRWXU, 1);
    sem_unlink("/died");
    qw->died = sem_open("/died", O_CREAT | O_EXCL, S_IRWXU, 1);
    sem_unlink("/finishh");
    qw->finish = sem_open("/finishh", O_CREAT | O_EXCL, S_IRWXU, 0);
    if (qw->forks == SEM_FAILED || qw->print == SEM_FAILED
     || qw->died == SEM_FAILED || qw->ptr == NULL)
        return (-1);
    if (ac == 6)
        qw->count = ft_atoi(av[5]);
    else
        qw->count = -1;
    qw->dead = 1;
    while (qw->i < qw->num_phil)
    {
        ft_end_init(ac, av, qw, qw->i);
        qw->i++;
    }
    return (0);
}