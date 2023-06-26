#include "../../inc/philosophers.h"

int	philosopher_takes_forks(philo_t *philosophers)
{
	if (philosophers->id % 2 == 0)
		pthread_mutex_lock(philosophers->right_fork);
	else
		pthread_mutex_lock(philosophers->left_fork);
	if (!philosopher_is_dead(philosophers))
		print_message("has taken a fork", philosophers);
	if (philosophers->id % 2 == 0)
	{
		if (pthread_mutex_lock(philosophers->left_fork) != 0)
			return (pthread_mutex_unlock(philosophers->right_fork), 1);
		if (!philosopher_is_dead(philosophers))
			print_message("has taken a fork", philosophers);
	}
	else
	{
		if (pthread_mutex_lock(philosophers->right_fork) != 0)
			return (pthread_mutex_unlock(philosophers->left_fork), 1);
		if (!philosopher_is_dead(philosophers))
			print_message("has taken a fork", philosophers);
	}
	return (0);
}

void	philosopher_is_eating(philo_t *philosophers)
{
	print_message("is eating", philosophers);
	pthread_mutex_lock(&philosophers->general->mutex);
	philosophers->last_meal = get_time() - philosophers->general->starting_time;
	philosophers->time_to_die = philosophers->last_meal + philosophers->general->time_to_die;
	pthread_mutex_unlock(&philosophers->general->mutex);
	ft_sleep(philosophers->general->time_to_eat, philosophers);
	pthread_mutex_lock(&philosophers->general->mutex);
	if (philosophers->number_of_meals != 1)
		philosophers->number_of_meals++;
	pthread_mutex_unlock(&philosophers->general->mutex);
	pthread_mutex_unlock(philosophers->left_fork);
	pthread_mutex_unlock(philosophers->right_fork);
}

void	philosophers_is_sleeping(philo_t *philosophers)
{
	print_message("is_sleeping", philosophers);
	ft_sleep(philosophers->general->time_to_sleep, philosophers);
}

void	philosophers_is_thinking(philo_t *philosophers)
{
	print_message("is thinking", philosophers);
}

int	philosopher_is_dead(philo_t *philosophers)
{
	pthread_mutex_lock(&philosophers->general->mutex);
	if (philosophers->general->philosopher_dead == 1)
	{
		pthread_mutex_unlock(&philosophers->general->mutex);
		return (1);
	}
	pthread_mutex_unlock(&philosophers->general->mutex);
	return (0);
}