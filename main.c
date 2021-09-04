/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:16:21 by murachid          #+#    #+#             */
/*   Updated: 2021/08/31 18:17:20 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosphers.h"

int		main(int argc, char **argv)
{
	t_data			data;
	t_philo			*philosophers;
	pthread_t		*threads;
	pthread_mutex_t	*mut;
	pthread_mutex_t write_permission;

	if (argc < 5 || argc > 6 || init_struct(&data, argc, argv))
	{
		printf("bad arguments\n");
		return 0;
	}
	philosophers = malloc(sizeof(t_philo) * data.nb_phil);
	if (!philosophers)
	{
		printf("error\n");
		return(0);
	}
	int i = 0;
	mut = malloc(sizeof(pthread_mutex_t) * data.nb_phil);
	while(i < data.nb_phil)
	{
		if (pthread_mutex_init(&mut[i], NULL))
			return (1);
		i++; 
	}
	i = -1;
	pthread_mutex_init(&write_permission, NULL);
	while (++i < data.nb_phil)
	{
		philosophers[i].mut = mut;
		philosophers[i].id = i;
		philosophers[i].last_ate_mutex = write_permission;
	}
	threads = malloc(sizeof(pthread_t) * data.nb_phil);
	if (!threads)
	{
		printf("error\n");
		return(0);
	}
	if (setup_threads(data, philosophers, threads))
	{
		printf("error\n");
		return(0);
	}		
	free(mut);
	free(philosophers);
	free(threads);
	return (0);
}
