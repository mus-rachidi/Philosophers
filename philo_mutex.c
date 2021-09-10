/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 17:04:14 by murachid          #+#    #+#             */
/*   Updated: 2021/09/10 14:40:03 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosphers.h"

void	*ft_print(pthread_mutex_t *write_per, char *string, int id)
{
	struct timeval	time;
	unsigned long	t;

	pthread_mutex_lock(write_per);
	gettimeofday(&time, NULL);
	t = time.tv_sec * 1000 + time.tv_usec / 1000;
	printf("%lu %d %s", t, id, string);
	pthread_mutex_unlock(write_per);
	return (NULL);
}

void	*philosopher(void *arg)
{
	t_philosophers	*ph;

	ph = (t_philosophers *)arg;
	while (1)
	{
		pthread_mutex_lock(&ph->p_mutex[ph->id]);
		ft_print(&ph->write_mutex, "has taken a fork\n", ph->id + 1);
		pthread_mutex_lock(&ph->p_mutex[(ph->id + 1) % ph->data.nb_phil]);
		ft_print(&ph->write_mutex, "has taken a fork\n", ph->id + 1);
		ft_print(&ph->write_mutex, "is eating\n", ph->id + 1);
		my_sleep(ph->data.time_to_eat * 1000);
		ph->nb_ate++;
		ph->last_ate = ft_microseconde();
		pthread_mutex_unlock(&ph->p_mutex[(ph->id + 1) % ph->data.nb_phil]);
		pthread_mutex_unlock(&ph->p_mutex[ph->id]);
		ft_print(&ph->write_mutex, "is sleeping\n", ph->id + 1);
		my_sleep(ph->data.time_to_sleep * 1000);
		ft_print(&ph->write_mutex, "is thinking\n", ph->id + 1);
	}
	return (NULL);
}