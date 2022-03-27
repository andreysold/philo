# Philosophers

## Проблема обедающих философов (MANDATORY)
____
#### Проблема обедающих философов является типичная проблема при разработке параллельных алгоритмов для иллюстрации проблем синхронизации и методов их решения.
___

## Разрешенные функции основной части

__memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock__

* __Избежание дедлока и решение задачи происходит засчет мьютексов и тредов __

## Аргументы программы
* number_of_philosophers: количество философов, а также количество
вилок.
* time_to_die (в миллисекундах): если философ не начал есть time_to_die
миллисекунд с начала их последнего приема пищи или начала симуляции, они умирают.
* time_to_eat (в миллисекундах): время, которое требуется философу, чтобы поесть.
За это время им нужно будет держать две вилки.
* time_to_sleep (в миллисекундах): время, которое философ проведет во сне.
* number_of_times_each_philosopher_must_eat (необязательный аргумент): если все философы ели по крайней мере number_of_times_each_philosopher_must_eat раз симуляция останавливается. Если не указано, моделирование останавливается, когда
философ умирает.

# Запуск программы
* git clone philo
* cd philo/philo
* make
* ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
  
# Проблема обедающих философов (BONUS)

## Разрешенные функции основной части
__memset, printf, malloc, free, write, fork, kill,
exit, pthread_create, pthread_detach, pthread_join,
usleep, gettimeofday, waitpid, sem_open, sem_close,
sem_post, sem_wait, sem_unlink__
____
* __Избежание дедлока и решение задачи происходит засчет процессов и семафоров__
* __Кроме использования семафров вместо мьютексов, процессов вместо тредов, разница заключается в том, что вилки философоф не проинициализированы каждому. То есть вилки находятся в середине стола__

## Аргументы программы
* Аргументы как и в основной части

# Запуск программы
* git clone philo
* cd philo/philo_bonus
* make
* ./philo_bonus [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
  
