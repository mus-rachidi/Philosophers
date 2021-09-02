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

void ft_print(t_philo *philosopher, t_data *data)
{
	printf("======================>>>>\nid = %d\n",philosopher->id);
	printf("nb_phil = %d\n",data->nb_phil);
	printf("time_to_die = %d\n",data->time_to_die);
	printf("time_to_eat = %d\n",data->time_to_eat);
	printf("time_to_sleep = %d\n",data->time_to_sleep);
	printf("eat_times = %d\n",data->eat_times);
	printf("state = %d\n",data->state);
	printf("starttime = %lu\n",data->starttime);
	printf("last_ate = %lu\n",philosopher->last_ate);
	printf("philosopher->lfork_mutex = %p \nphilosopher->rfork_mutex = %p \n",(void*)philosopher->lfork_mutex, (void*)philosopher->rfork_mutex);
}

int		main(int argc, char **argv)
{
	t_data		*data;
	t_philo		*philosophers;
	pthread_t	*threads;
	data = malloc(sizeof(t_data));
	if (!data)
	{
		printf("error\n");
		return(0);
	}
	if (argc < 5 || argc > 6 || init_struct(data, argc, argv))
	{
		printf("bad arguments\n");
		return 0;
	}
	philosophers = malloc(sizeof(t_philo) * data->nb_phil);
	if (!philosophers)
	{
		printf("error\n");
		return(0);
	}
	threads = malloc(sizeof(pthread_t) * data->nb_phil);
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
	free(data);
	free(philosophers);
	free(threads);
	return (0);
}
