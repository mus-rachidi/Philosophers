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
	unsigned long	starttime;
}	t_data;

typedef struct	s_philosophers
{
	int				id;
	unsigned long	last_ate;
	int				nb_ate;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	*p_mutex;
}	t_philosophers;

long	ft_microseconde(void);
void	ft_putstr_fd(char *str, int fd);
int		ft_atoi(const char *str);
int		initialize_philosopher(t_philosophers *philosopher);
int		init_struct(t_data *data, int argc, char **argv);
int		main_threads(t_data data, t_philosophers *philosophers, pthread_t *threads);
void	*ft_memset(void *dest, int c, size_t n);
int		init_struct(t_data *data, int argc, char **argv);
void	*philosopher(void *arg);
long	ft_milliseconde(void);
#endif
