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
}				t_data;

typedef struct	s_philo
{
	int				id;
	unsigned long	last_ate;
	pthread_mutex_t	*lfork_mutex;
	pthread_mutex_t	*rfork_mutex;
	pthread_mutex_t	last_ate_mutex;
	t_data			*data;
}				t_philo;	//t_data			*data;


void	ft_putstr_fd(char *str, int fd);
int			ft_atoi(const char *str);








#endif