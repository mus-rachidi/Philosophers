/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 09:27:41 by murachid          #+#    #+#             */
/*   Updated: 2021/09/12 09:31:28 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosphers.h"

int	check_died(t_data data, t_philosophers *p)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < data.nb_phil)
	{
		if ((ft_microseconde() - p[i].last_ate) > data.time_to_die * 1000)
		{
			ft_print_die("is died\n", p);
			return (0);
		}
		if (data.eat_times != -1 && (p[i].nb_ate >= data.eat_times))
		{
			j++;
			if (j == data.nb_phil)
				return (0);
		}
		i++;
		usleep(500);
	}
	return (1);
}
