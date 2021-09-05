/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philospher_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:16:36 by murachid          #+#    #+#             */
/*   Updated: 2021/09/05 17:19:30 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosphers.h"

int		setup_threads(t_data data, t_philosophers *philosophers, pthread_t *threads)
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
