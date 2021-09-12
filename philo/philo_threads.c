/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:16:36 by murachid          #+#    #+#             */
/*   Updated: 2021/09/12 09:31:25 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosphers.h"

int	main_threads(t_data data, t_philosophers *p, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < data.nb_phil)
	{
		if (pthread_create(&threads[i], NULL, philosopher, &p[i]))
			return (1);
		usleep(50);
		++i;
	}
	while (1)
	{
		if (check_died(data, p) == 0)
			return (0);
	}
	i = 0;
	while (i < data.nb_phil)
	{
		pthread_join(threads[i++], NULL);
		++i;
	}
	return (0);
}
