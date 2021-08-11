#include "philosphers.h"

int    intialize_data(t_phil *data,int argc, char **argv)
{

    data->number_of_philo = ft_atoi(argv[1]);
    data->time_to_eat = ft_atoi(argv[2]);
    data->time_to_die = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    data->times_must_eat = 0;
    if(argc == 6)
        data->times_must_eat = ft_atoi(argv[5]);
    return(0);
}