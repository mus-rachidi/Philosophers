/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosphers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:16:39 by murachid          #+#    #+#             */
/*   Updated: 2021/09/11 14:19:49 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSPHERS_H
# define PHILOSPHERS_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int				nb_phil;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		eat_times;
	unsigned long	starttime;
}				t_data;

typedef struct s_philosophers
{
	int				id;
	unsigned long	last_ate;
	int				nb_ate;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	*p_mutex;
	t_data			data;
}				t_philosophers;

void	ft_print_die(char *string, t_philosophers *ph);
int		ft_error(int argc, char **argv);
void	my_sleep(long long microseconde);
long	ft_milliseconde(void);
int		ft_atoi(const char *str);
int		main_threads(t_data data, t_philosophers *p, pthread_t *threads);
int		init_data(t_data *data, int argc, char **argv);
void	*philosopher(void *arg);
void	ft_print(char *string, t_philosophers *ph);
int		alloc_and_init(t_data data);
long	ft_microseconde(void);
#endif
