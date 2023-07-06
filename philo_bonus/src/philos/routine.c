/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:35:18 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/06 11:52:25 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers_bonus.h"

/*	Pick two forks from the middle of the table and print the according
	message. */
static void	pick_forks(t_philo *philo)
{
	sem_wait(philo->args->sem_forks);
	monitoring(philo, FORK);
	sem_wait(philo->args->sem_forks);
	monitoring(philo, FORK);
}

/*	Drop two forks on the middle of the table and print the according
	message. */
static void	drop_forks(t_philo *philo)
{
	monitoring(philo, DROP);
	monitoring(philo, DROP);
	sem_post(philo->args->sem_forks);
	sem_post(philo->args->sem_forks);
}

/*	Handle the meal of a philosopher and print the according
	message. */
static void	eat(t_philo *philo)
{
	pick_forks(philo);
	sem_wait(philo->sem_lock_death);
	monitoring(philo, EAT);
	philo->last_meal_time = get_time();
	sem_post(philo->args->sem_meal);
	sem_post(philo->sem_lock_death);
	usleep(philo->args->time_to_eat * MICROSEC);
	drop_forks(philo);
}

/*	Handle the sleep of a philosopher and print the according
	message. */
static void	_sleep(t_philo *philo)
{
	monitoring(philo, SLEEP);
	usleep(philo->args->time_to_sleep * MICROSEC);
}

/*	Handle the basic routine of philosophers. */
void	routine(t_philo *philo)
{
	while (true)
	{
		eat(philo);
		_sleep(philo);
		monitoring(philo, THINK);
	}
}