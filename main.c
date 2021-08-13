#include "philosphers.h"

void ft_print(t_philo *philosopher, t_data *data)
{
  printf("nb_phil = %d\n",data->nb_phil);
  printf("time_to_die = %d\n",data->time_to_die);
  printf("time_to_eat = %d\n",data->time_to_eat);
  printf("time_to_sleep = %d\n",data->time_to_sleep);
  printf("eat_times = %d\n",data->eat_times);
  printf("state = %d\n",data->state);
  printf("starttime = %d\n",data->starttime);
  printf("id = %d\n",philosopher->id);
  printf("last_iate = %d\n",philosopher->last_ate);
}

int		initialize_philosopher(t_philo *philosopher, t_data *data, int i)
{
	memset(philosopher, 0, sizeof(t_philo));
	philosopher->id = i + 1;
	philosopher->data = data;
	philosopher->lfork_mutex = &data->forks[i];
	philosopher->rfork_mutex = &data->forks[(i + 1) % data->nb_phil];
	// philosopher->last_ate = get_time_ms();
	// if (pthread_mutex_init(&philosopher->last_ate_mutex, NULL))
	// 	return (1);
	return (0);
}

int		init_struct(t_data *data, int argc, char **argv)
{
	memset(data, 0, sizeof(t_data));
	data->nb_phil = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->eat_times = -1;
	if (argc == 6)
		data->eat_times = ft_atoi(argv[5]);
	if (data->nb_phil <= 0 || data->time_to_die <= 0 || data->time_to_eat <= 0
	|| data->time_to_sleep <= 0 || (argc == 6 && data->eat_times < 0))
		return (1);

	return (0);
}

int		setup_threads(t_data *data, t_philo *philosophers, pthread_t *threads)
{
	int			i;

	i = 0;
	while (i < data->nb_phil)
	{
    
		if (initialize_philosopher(&philosophers[i], data, i))
			return (1);
		// if (pthread_create(&threads[i], NULL, start_philosopher,
		// 	&philosophers[i]))
		//	return (1);
		++i;
	}
	// mr_manager(philosophers, data);
	// i = 0;
	// while (i < data->nb_phil)
	// {
	// 	pthread_join(threads[i], NULL);
	// 	++i;
	// }
	return (0);
}

int		main(int argc, char **argv)
{
	t_data		data;
	t_philo   *philosophers;
	pthread_t	*threads;

	if (argc < 5 || argc > 6 || init_struct(&data, argc, argv))
  {
    ft_putstr_fd("bad arguments\n", 1);
    return 0;
  }
	philosophers = malloc(sizeof(t_philo) * data.nb_phil);
	if (!philosophers)
		ft_putstr_fd("cant malloc\n", 1); 
	threads = malloc(sizeof(pthread_t) * data.nb_phil);
	if (!threads)
		return (1);
  if (setup_threads(&data, philosophers, threads))
		ft_putstr_fd("something went horribly wrong\n", 1);
  ft_print(philosophers, &data);
	free(data.forks);
	free(philosophers);
	free(threads);
	return (0);
}
