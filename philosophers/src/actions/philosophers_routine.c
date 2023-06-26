#include "../../inc/philosophers.h"

void	*philosophers_routine(void	*arguments)
{
	philo_t *philosophers;

	philosophers = (philo_t *)arguments;
	while (philosophers->general->philosopher_dead == 0)
	{
		if (philosopher_is_dead(philosophers))
			return (0);
		philosopher_takes_forks(philosophers);
		if (philosopher_is_dead(philosophers))
		{
			pthread_mutex_unlock(philosophers->left_fork);
			pthread_mutex_unlock(philosophers->right_fork);
			return (0);
		}
		philosopher_is_eating(philosophers);
		if (philosopher_is_dead(philosophers))
			return (0);
		philosophers_is_sleeping(philosophers);
		if (philosopher_is_dead(philosophers))
			return (0);
		philosophers_is_thinking(philosophers);
	}
	return (0);
}

void	join_threads(general_t *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_join(data->philosophers[i].thread_id, NULL);
		i++;
	}
}

void	begin_philosophers_routine(general_t *data)
{
	int	i;

	i = 0;
	data->starting_time = get_time();
	while (i < data->number_of_philosophers)
	{
		pthread_create(&data->philosophers[i].thread_id, NULL, &philosophers_routine, (void *)&data->philosophers[i]);
		i++;
	}
	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_join(data->philosophers[i].thread_id, NULL);
		i++;
	}
}