/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 09:30:06 by murachid          #+#    #+#             */
/*   Updated: 2021/09/12 09:31:32 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosphers.h"

void	ft_print(char *string, t_philosophers *ph)
{
	struct timeval	time;
	unsigned long	t;

	pthread_mutex_lock(&ph->write_mutex);
	gettimeofday(&time, NULL);
	t = time.tv_sec * 1000 + time.tv_usec / 1000;
	printf("%lu %d %s", t, ph->id + 1, string);
	pthread_mutex_unlock(&ph->write_mutex);
}

void	ft_print_die(char *string, t_philosophers *ph)
{
	struct timeval	time;
	unsigned long	t;

	pthread_mutex_lock(&ph->write_mutex);
	gettimeofday(&time, NULL);
	t = time.tv_sec * 1000 + time.tv_usec / 1000;
	printf("%lu %d %s", t, ph->id + 1, string);
	pthread_mutex_unlock(&ph->write_mutex);
}
