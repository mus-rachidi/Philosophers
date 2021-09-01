/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philospher_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:16:36 by murachid          #+#    #+#             */
/*   Updated: 2021/08/31 18:16:37 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosphers.h"

int		initialize_philosopher(t_philo *philosopher, t_data *data, int i)
{
	ft_memset(philosopher, 0, sizeof(t_philo));
	philosopher->id = i + 1;
	philosopher->lfork_mutex = &data->forks[i];
	philosopher->rfork_mutex = &data->forks[(i + 1) % data->nb_phil];
 	// philosopher->last_ate = get_time_ms();
	if (pthread_mutex_init(&philosopher->last_ate_mutex, NULL))
		return (1);
	ft_print(philosopher, data);
	return (0);
}

int		init_struct(t_data *data, int argc, char **argv)
{
	ft_memset(data, 0, sizeof(t_data));
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

void *philosopher(t_data *data)
{
	data->nb_phil += 1;
	printf("%d\n",data->nb_phil);
	sleep(3);
	printf("%d\n",data->nb_phil); 	
	return(0);
}

int		setup_threads(t_data *data, t_philo *philosophers, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < data->nb_phil)
	{
		if (initialize_philosopher(&philosophers[i], data, i))
			return (1);
		if (pthread_create(&threads[i], NULL, philosopher, &philosophers[i]))
			return (1);
		++i;
	}
	i = 0;
	while (i < data->nb_phil)
	{
			pthread_join(threads[i], NULL);
			++i;
	}
	return (0);
}
