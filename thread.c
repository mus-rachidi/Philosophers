/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 17:04:14 by murachid          #+#    #+#             */
/*   Updated: 2021/09/07 14:35:00 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosphers.h"

long	ft_microseconde(void)
{
	struct timeval	time;
	long			time_now;

	gettimeofday(&time, NULL);
	time_now = time.tv_usec + (time.tv_sec * 1000000);
	return (time_now);
}

void *ft_print(pthread_mutex_t *write_per, char *string ,int id)
{
	struct timeval time;
	unsigned long t;
	pthread_mutex_lock(write_per);
	gettimeofday(&time, NULL);
	t = time.tv_sec * 1000 + time.tv_usec / 1000;
	printf("%lu %d %s",t ,id, string);
	pthread_mutex_unlock(write_per);
	return(NULL);
}

void	*philosopher(void *arg)
{
	t_philosophers	*ph;
	t_data			*data;
	ph = (t_philosophers *)arg;
	while(1)
	{
		pthread_mutex_lock(&ph->p_mutex[ph->id]);
		ft_print(&ph->write_mutex,"has taken a fork\n",ph->id + 1);
		pthread_mutex_lock(&ph->p_mutex[(ph->id + 1) % data->nb_phil]);
		ft_print(&ph->write_mutex,"has taken a fork\n",ph->id + 1);
		ft_print(&ph->write_mutex,"is eating\n",ph->id + 1);
		usleep(data->time_to_eat);
		ph->last_ate = ft_milliseconde();
		ph->nb_ate++;
		pthread_mutex_unlock(&ph->p_mutex[(ph->id + 1) % data->nb_phil]);
		pthread_mutex_unlock(&ph->p_mutex[ph->id]);
		ft_print(&ph->write_mutex,"is sleeping\n",ph->id + 1);
		usleep(data->time_to_sleep);
		ft_print(&ph->write_mutex,"is thinking\n",ph->id + 1);
	}
	return(NULL);
}
