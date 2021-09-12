/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 17:04:14 by murachid          #+#    #+#             */
/*   Updated: 2021/09/12 09:31:30 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosphers.h"

void	*philosopher(void *arg)
{
	t_philosophers	*ph;

	ph = (t_philosophers *)arg;
	while (1)
	{
		pthread_mutex_lock(&ph->p_mutex[ph->id]);
		ft_print("has taken a fork\n", ph);
		pthread_mutex_lock(&ph->p_mutex[(ph->id + 1) % ph->data.nb_phil]);
		ft_print("has taken a fork\n", ph);
		ft_print("is eating\n", ph);
		my_sleep(ph->data.time_to_eat * 1000);
		ph->nb_ate++;
		ph->last_ate = ft_microseconde();
		pthread_mutex_unlock(&ph->p_mutex[(ph->id + 1) % ph->data.nb_phil]);
		pthread_mutex_unlock(&ph->p_mutex[ph->id]);
		ft_print("is sleeping\n", ph);
		my_sleep(ph->data.time_to_sleep * 1000);
		ft_print("is thinking\n", ph);
	}
	return (NULL);
}
