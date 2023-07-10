/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:42:02 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/10 12:14:57 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers.h"

/*	Helper function that lock the mutex right/left forks. */
static void	pick_forks(t_philo *philo)
{
	if (philo->left_fork < philo->right_fork)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	}
	monitoring(philo, FORK);
	monitoring(philo, FORK);
}

/*	Helper function that unlock the mutex right/left forks. */
static void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	monitoring(philo, DROP);
	monitoring(philo, DROP);
}

/*	Helper function that handles the eating of the philosophers. */
static void	eat(t_philo *philo)
{
	pick_forks(philo);
	pthread_mutex_lock(&philo->can_die);
	monitoring(philo, EAT);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->can_die);
	usleep(philo->args->time_to_eat * MICROSEC);
	drop_forks(philo);
	pthread_mutex_lock(&philo->eaten_meals_mutex);
	philo->eaten_meals += 1;
	pthread_mutex_unlock(&philo->eaten_meals_mutex);
}

/*	Helper function that handles the sleep of the philosophers. */
static void	_sleep(t_philo *philo)
{
	monitoring(philo, SLEEP);
	usleep(philo->args->time_to_sleep * MICROSEC);
}

/*	Function that handles the routine of the philosophers. */
void	*routine(void	*philo)
{
	t_philo	*casted;

	casted = (t_philo *)philo;
	while (!casted->args->someone_died && !all_ate_n_times(casted))
	{
		if (casted->args->nbr_of_philo == 1)
		{
			pthread_mutex_lock(casted->left_fork);
			monitoring(philo, FORK);
			casted->last_meal_time = get_time();
			pthread_mutex_unlock(casted->left_fork);
			return (NULL);
		}
		eat(casted);
		_sleep(casted);
		monitoring(casted, THINK);
	}
	return (NULL);
}
