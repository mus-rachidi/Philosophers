/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosphers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:16:39 by murachid          #+#    #+#             */
/*   Updated: 2021/08/31 18:16:56 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSPHERS_H
# define PHILOSPHERS_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
# include <string.h>

typedef struct	s_data
{
	int				nb_phil;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_times;
	int				state;
	pthread_mutex_t	state_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	pen;
	unsigned long	starttime;
}	t_data;

typedef struct	s_philo
{
	int	id;
	unsigned long	last_ate;
	pthread_mutex_t	*lfork_mutex;
	pthread_mutex_t	*rfork_mutex;
	pthread_mutex_t	last_ate_mutex;
}	t_philo;

void	ft_print(t_philo *philosopher, t_data *data);
void	ft_putstr_fd(char *str, int fd);
int		ft_atoi(const char *str);
int		initialize_philosopher(t_philo *philosopher, t_data *data, int i);
int		init_struct(t_data *data, int argc, char **argv);
int		setup_threads(t_data *data, t_philo *philosophers, pthread_t *threads);
void	*ft_memset(void *dest, int c, size_t n);

#endif
