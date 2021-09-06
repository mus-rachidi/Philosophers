/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philospher_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:16:36 by murachid          #+#    #+#             */
/*   Updated: 2021/09/06 18:07:58 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosphers.h"
int  check_died(void)
{
	t_data data;
	t_philosophers philosopher;
	unsigned long time_now;
	unsigned long time_deferent;

	unsigned long time_ate_last;
	time_now = ft_microseconde();
	while(1)
	{
		time_deferent = time_now - philosopher.last_ate;
		printf("time_deferent = %lu philosopher.last_ate = %lu\n",time_deferent, philosopher.last_ate);
		if(time_deferent > data.time_to_die)
			return(1);
	}
}
int		main_threads(t_data data, t_philosophers *philosophers, pthread_t *threads)
{
	int	i;
	i = 0;
	while (i < data.nb_phil)
	{
		
		if (pthread_create(&threads[i], NULL, philosopher, &philosophers[i]))
			return (1);
		if (check_died() == 1)
		{
			printf("%lu %d %s",philosophers->last_ate ,i, "is died\n");
			return(0);
		}
		++i;
		usleep(400);
	}
	i = 0;
	while (i < data.nb_phil)
	{
		pthread_join(threads[i], NULL);
		++i;
	}
	return (0);
}
