#include "philosphers.h" 

int		initialize_philosphers(t_philo *philosphers, t_phil *data, int i)
{
	//memset(philosphers, 0, sizeof(t_philo));
	philosphers->id = i + 1;
	philosphers->data = data;
	philosphers->lfork_mutex = &data->forks[i];
	philosphers->rfork_mutex = &data->forks[(i + 1) % data->nb_phil];
	//philosphers->last_ate = get_time_ms();
	if (pthread_mutex_init(&philosphers->last_ate_mutex, NULL))
		return (1);
	return (0);
}

void ft_philo( t_phil *data ,t_philo *philosphers, pthread_t *threads)
{
    int i;
    i = 0;
    while( i < data->number_of_philo)
    {
      if (initialize_philosphers(&philosphers[i], data, i))
			  return (1);
      //pthread_create(&threads[i], NULL, start_philospher, &philosphers[i]);
      i++;
    }
    i = 0;
    while(i < data->number_of_philo)
    {
        pthread_join(threads[i], NULL);
        i++;
    }
}

int main(int argc, char **argv)
{
    pthread_t	*threads;
    t_phil      data;
    t_philo philosphers;
    if (argc < 5 || argc > 6 || intialize_data(&data, argc, argv))
		ft_putstr_fd("bad arguments\n", 1);
    threads = malloc(sizeof(pthread_t) * data.number_of_philo);
    if (!threads)
		ft_putstr_fd("cant malloc\n", 1);
    ft_philo(&data, philosphers, threads);
    printf("data.number_of_philo = %d\ndata.time_to_eat = %d\ndata.time_to_die = %d\ndata.time_to_sleep = %d\ndata->times_must_eat = %d", 
    data.number_of_philo, 
    data.time_to_eat, 
    data.time_to_die,   
    data.time_to_sleep, 
    data.times_must_eat);
    return(0); 
}