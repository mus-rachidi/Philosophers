/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 17:03:18 by murachid          #+#    #+#             */
/*   Updated: 2021/09/11 14:13:07 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosphers.h"

pthread_mutex_t	*array(t_data data)
{
	int				i;
	pthread_mutex_t	*array_mutex;

	i = 0;
	array_mutex = malloc(sizeof(pthread_mutex_t) * data.nb_phil);
	while (i < data.nb_phil)
	{
		if (pthread_mutex_init(&array_mutex[i], NULL))
			return (NULL);
		i++;
	}
	return (array_mutex);
}

int	init_philosopher(t_philosophers	*philosophers, t_data data)
{
	int				i;
	pthread_mutex_t	write_permission;
	pthread_mutex_t	*forks;

	i = 0;
	forks = array(data);
	pthread_mutex_init(&write_permission, NULL);
	while (i < data.nb_phil)
	{
		philosophers[i].p_mutex = forks;
		philosophers[i].id = i;
		philosophers[i].write_mutex = write_permission;
		philosophers[i].nb_ate = 0;
		philosophers[i].last_ate = ft_microseconde();
		philosophers[i].data = data;
		i++;
	}
	return (0);
}

int	alloc_and_init(t_data data)
{
	t_philosophers	*philosophers;
	pthread_t		*threads;
	int				i;

	i = 0;
	philosophers = malloc(sizeof(t_philosophers) * data.nb_phil);
	if (!philosophers)
	{
		printf("error\n");
		return (1);
	}
	init_philosopher(philosophers, data);
	threads = malloc(sizeof(pthread_t) * data.nb_phil);
	if (!threads || main_threads(data, philosophers, threads) == 1)
	{
		printf("error\n");
		return (1);
	}	
	free(philosophers);
	free(threads);
	return (0);
}

int	init_data(t_data *data, int argc, char **argv)
{
	data->nb_phil = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->eat_times = ft_atoi(argv[5]);
	else
		data->eat_times = -1;
	if (data->nb_phil <= 0 || data->time_to_die <= 0 || data->time_to_eat <= 0
		|| data->time_to_sleep <= 0 || (argc == 6 && data->eat_times < 0))
		return (1);
	return (0);
}
