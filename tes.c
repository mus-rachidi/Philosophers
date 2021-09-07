
int	status_life(int i, long is_philo_die)
{
	t_init	*all;

	all = iniit_t();
	is_philo_die = (current_time_micr() - all->profile[i].start_eats);
	if (is_philo_die >= (all->die_time * 1000))
	{
		new_print("is dead", i + 1, 2);
		return (1);
	}
	return (0);
}
int	check_life(void)
{
	t_init	*all;
	int		i;
	long	is_philo_die;
	int		done_eating;

	all = iniit_t();
	while (1)
	{
		i = -1;
		done_eating = 0;
		while (++i < all->nbr_of_philo)
		{
			if (status_life(i, done_eating) == 1)
				return (1);
			if (all->nbr_eat != -1 \
				&& all->profile[i].nbr_times_eat >= all->nbr_eat)
			{	
				done_eating++;
				if (done_eating == all->nbr_of_philo)
					return (1);
			}
		}
		usleep(15);
	}
	return (0);
}
