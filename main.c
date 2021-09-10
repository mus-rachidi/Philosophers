/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:16:21 by murachid          #+#    #+#             */
/*   Updated: 2021/09/10 09:55:09 by murachid         ###   ########.fr       */
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

	i = 0;
	pthread_mutex_init(&write_permission, NULL);
	while (i < data.nb_phil)
	{
		philosophers[i].p_mutex = array(data);
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
	return (0);
	free(philosophers);
	free(threads);
}

int	main(int argc, char **argv)
{
	int				i;
	t_data			data;

	if (argc < 5 || argc > 6 || init_struct(&data, argc, argv))
	{
		printf("bad arguments\n");
		return (1);
	}
	return (alloc_and_init(data));
}
