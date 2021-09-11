/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_times.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:29:15 by murachid          #+#    #+#             */
/*   Updated: 2021/09/11 13:58:41 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosphers.h"

long	ft_milliseconde(void)
{
	struct timeval	time;
	long			time_now;

	gettimeofday(&time, NULL);
	time_now = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (time_now);
}

long	ft_microseconde(void)
{
	struct timeval	time;
	long			time_now;

	gettimeofday(&time, NULL);
	time_now = time.tv_sec * 1000000 + time.tv_usec;
	return (time_now);
}

void	my_sleep(long long microseconde)
{
	long long			first_time;

	first_time = ft_microseconde();
	usleep(microseconde - 60000);
	while ((ft_microseconde() - first_time) < microseconde)
	{
	}
}
