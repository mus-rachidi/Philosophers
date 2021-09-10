/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:16:36 by murachid          #+#    #+#             */
/*   Updated: 2021/09/10 09:25:05 by murachid         ###   ########.fr       */
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

void	check_died(t_data data, t_philosophers *p)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < data.nb_phil)
	{
		if ((ft_microseconde() - p[i].last_ate) > (data.time_to_die) * 1000)
		{
			ft_print(&p->write_mutex, "is died\n", p->id + 1);
			exit(0);
		}
		if (data.eat_times != -1 && (p[i].nb_ate > data.eat_times))
		{
			j++;
			if (j == data.nb_phil)
				exit(0);
		}
		i++;
		usleep(500);
	}
}

int	main_threads(t_data data, t_philosophers *p, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < data.nb_phil)
	{
		p[i].last_ate = ft_microseconde();
		if (pthread_create(&threads[i], NULL, philosopher, &p[i]))
			return (1);
		usleep(500);
		++i;
	}
	while (1)
		check_died(data, p);
	i = 0;
	while (i < data.nb_phil)
	{
		pthread_join(threads[i++], NULL);
		++i;
	}
	return (0);
}
