/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:16:36 by murachid          #+#    #+#             */
/*   Updated: 2021/09/08 16:30:47 by murachid         ###   ########.fr       */
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

void		check_died(t_philosophers *philosopher,t_data data)
{
	unsigned long time_deferent;
	unsigned long time_now = ft_microseconde();

	time_deferent = (time_now - philosopher->last_ate);
	if(time_deferent >= (data.time_to_die) * 1000)
	{
		// printf("%ld %d is deid\n", time_now, philosopher->id + 1);
		ft_print(&philosopher->write_mutex, "is dead\n", philosopher->id + 1);
		
		exit(0);
	}
}

int		main_threads(t_data data, t_philosophers *philosophers, pthread_t *threads)
{
	int	i;
	int j;

	i = 0;
	while (i < data.nb_phil)
	{
		philosophers[i].last_ate = ft_microseconde();
		if (pthread_create(&threads[i], NULL, philosopher, &philosophers[i]))
			return (0);
		usleep(500);
		++i;
	}

	while(1)
	{
		i = 0;
		while(i < data.nb_phil)
		{
			check_died(&philosophers[i], data);	
			i++;		
		}
		usleep(500);
	}
	i = 0;
	while (i < data.nb_phil)
	{
		pthread_join(threads[i], NULL);
		++i;
	}
	return (0);
}
