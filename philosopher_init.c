/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 17:03:18 by murachid          #+#    #+#             */
/*   Updated: 2021/09/05 10:40:26 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosphers.h"

int		initialize_philosopher(t_philosophers *philosopher, int i)
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
