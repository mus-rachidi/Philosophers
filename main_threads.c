/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:16:36 by murachid          #+#    #+#             */
/*   Updated: 2021/09/07 14:36:50 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosphers.h"

long	ft_milliseconde(void)
{
	struct timeval	time;
	long			time_now;

	gettimeofday(&time, NULL);
	time_now = time.tv_usec / 1000 + (time.tv_sec * 1000);
	return (time_now);
}

int		check_died(t_philosophers *philosopher,t_data data)
{
	unsigned long time_deferent;
	int full = 0;
	unsigned long time = ft_milliseconde();
	if(philosopher->nb_ate == data.eat_times)
		full = 1;
	time_deferent = (time - philosopher->last_ate);
	if(time_deferent >= (data.time_to_die * 1000))
	{
		printf("%ld %d is deid\n", time, philosopher->id + 1);
		exit(0);
	}

	return(full);
}

int		main_threads(t_data data, t_philosophers *philosophers, pthread_t *threads)
{
	int	i;
	int j;
	int all_eat = 0;

	i = 0;
	while (i < data.nb_phil)
	{
		if (pthread_create(&threads[i], NULL, philosopher, &philosophers[i]))
			return (1);
		usleep(3000);
		++i;
	}
	while(1)
	{
		i = 0;
		while(i < data.nb_phil)
		{
			all_eat += check_died(&philosophers[i], data);
			i++;
		}
		if (all_eat >= data.nb_phil)
		{
			printf("====================+>ok\n");
			exit(0);
		}
		usleep(1000);
	}
	i = 0;
	while (i < data.nb_phil)
	{
		pthread_join(threads[i], NULL);
		++i;
	}
	return (0);
}
