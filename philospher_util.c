/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philospher_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:16:36 by murachid          #+#    #+#             */
/*   Updated: 2021/08/31 18:16:37 by murachid         ###   ########.fr       */
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

int		initialize_philosopher(t_philo *philosopher, int i)
{
 	philosopher->last_ate = ft_microseconde();
	return (0);
}

int		init_struct(t_data *data, int argc, char **argv)
{
	data->nb_phil = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->eat_times = ft_atoi(argv[5]);
	else
		data->eat_times = -1;
	if (data->nb_phil <= 0 || data->time_to_die <= 0 || data->time_to_eat <= 0
	|| data->time_to_sleep <= 0 || (argc == 6 && data->eat_times < 0))
		return (1);
	return (0);
}

void *ft_p(pthread_mutex_t *write_per, char *string ,int id)
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
	t_philo *ph;
	t_data *info;
	ph = (t_philo *)arg;
	while(1)
	{
		pthread_mutex_lock(&ph->mut[ph->id]);
		ft_p(&ph->last_ate_mutex,"has taken a fork\n",ph->id + 1);
		pthread_mutex_lock(&ph->mut[(ph->id - 1) % info->nb_phil]);
		ft_p(&ph->last_ate_mutex,"has taken a fork\n",ph->id + 1);
		pthread_mutex_unlock(&ph->mut[(ph->id- 1) % info->nb_phil]);
		pthread_mutex_unlock(&ph->mut[ph->id]);
		ft_p(&ph->last_ate_mutex,"is eating\n",ph->id + 1);
		usleep(info->time_to_eat * 1000);
	}
	return(NULL);
}

int		setup_threads(t_data data, t_philo *philosophers, pthread_t *threads)
{
	int	i;
	i = 0;
	while (i < data.nb_phil)
	{
		if (initialize_philosopher(&philosophers[i], i))
			return (1);
		if (pthread_create(&threads[i], NULL, philosopher, &philosophers[i]))
			return (1);
		++i;
	}
	i = 0;
	while (i < data.nb_phil)
	{
		pthread_join(threads[i], NULL);
		++i;
	}
	return (0);
}
