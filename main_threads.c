/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:16:36 by murachid          #+#    #+#             */
/*   Updated: 2021/09/09 18:44:30 by murachid         ###   ########.fr       */
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

void	check_died(t_data data, t_philosophers *philosophers)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	while(i < data.nb_phil)
	{
		if((ft_microseconde() - philosophers[i].last_ate) > (data.time_to_die) * 1000)
		{
			ft_print(&philosophers->write_mutex, "is died\n", philosophers->id + 1);	
			exit(0);
		}
		if(data.eat_times != -1 && (philosophers[i].nb_ate > data.eat_times))
		{
			j++;
			if(j == data.nb_phil)
				exit(0);
		}
		i++;
		usleep(500);
	}
}

int		main_threads(t_data data, t_philosophers *philosophers, pthread_t *threads)
{
	int	i;
	int retur;
	retur = 0;

	i = 0;
	while (i < data.nb_phil)
	{
		philosophers[i].last_ate = ft_microseconde();
		pthread_create(&threads[i], NULL, philosopher, &philosophers[i]);
		usleep(500);
		++i;
	}
	while(1)
		check_died(data, philosophers);
	i = 0;
	while (i < data.nb_phil)
	{
		pthread_join(threads[i], NULL);
		++i;
	}
}
