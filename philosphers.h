#ifndef PHILOSPHERS_H
# define PHILOSPHERS_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_phil
{
    int number_of_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int times_must_eat;
}t_phil;

typedef struct	s_philo
{
	int				id;
	unsigned long	last_ate;
	pthread_mutex_t	*lfork_mutex;
	pthread_mutex_t	*rfork_mutex;
	pthread_mutex_t	last_ate_mutex;
	//t_data			*data;
}				t_philo;

int    intialize_data(t_phil *data,int argc, char **argv);
void	ft_putstr_fd(char *str, int fd);
int			ft_atoi(const char *str);








#endif