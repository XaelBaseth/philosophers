/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:41:12 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/06 09:08:25 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers.h"

/*	Helper function that checks if a philosophers died of starvation. */
static void	check_starvation(t_philo *philos)
{
	int i;
	
	i = -1;
	while (++i < philos->args->nbr_of_philo)
	{
		pthread_mutex_lock(&philos[i].can_die);
		if (starved(&philos[i]))
		{
			monitoring(philos, DEAD);
			pthread_mutex_lock(&philos->satisfied_philo_mutex);
			philos->args->someone_died = true;
			pthread_mutex_unlock(&philos->satisfied_philo_mutex);
			pthread_mutex_unlock(&philos[i].can_die);
			return;
		}
		pthread_mutex_unlock(&philos[i].can_die);
	}
}

/*	Helper function that checks if every philosophers eats. */
static void	*supervisor(void *philos)
{	
	t_philo	*casted; 
	int		i;
	
	casted = (t_philo *)philos;
	while (!all_ate_n_times(casted) && !casted->args->someone_died)
	{
		check_starvation(casted);
		i = -1;
		while (++i < casted->args->nbr_of_philo)
		{
			pthread_mutex_lock(&casted[i].eaten_meals_mutex);
			pthread_mutex_lock(&casted->satisfied_philo_mutex);
			if (casted[i].eaten_meals == casted->args->must_eat_times)
				casted->args->satisfied_philos++;
			pthread_mutex_unlock(&casted[i].eaten_meals_mutex);
			pthread_mutex_unlock(&casted->satisfied_philo_mutex);
		}
	}
	if (casted->args->someone_died)
		printf("\033[31mA philosopher starved. End of experiment.\n\033[0m");
	else
		printf("\033[32mEvery Philosophers had %d meals!\n\033[0m", 
			casted->args->must_eat_times);
	return (NULL);
}

/*	Helper function that creates the thread that is used by the supervisor
	function. */
static bool	create_supervisor(t_args *args, pthread_mutex_t *forks,
							t_philo *philos)
{
	pthread_t	supervisor_tid;

	if (pthread_create(&supervisor_tid, NULL, supervisor,
		(void *)philos) != 0)
	{
		destroy(args, forks, philos);
		return (panic(THREAD_CREATE_ERR));
	}
	if (pthread_join(supervisor_tid, NULL) != 0)
	{
		destroy(args, forks, philos);
		return (panic(THREAD_JOIN_ERR));
	}
	return (true);
}

/*	Creates the threads for every philosopher and ensure that they eats with
	the help of the supervisor function. */
bool	create_threads(t_args *args, t_philo *philos, pthread_mutex_t *forks)
{
	int	i;

	i = -1;
	while (++i < args->nbr_of_philo)
	{
		philos[i].start_time = get_time();
		if (pthread_create(&philos[i].t_id, NULL,
				routine, (void *)&philos[i]) != 0)
		{
			destroy(args, forks, philos);
			return (panic(THREAD_CREATE_ERR));
		}
	}
	if (!create_supervisor(args, forks, philos))
		return (EXIT_FAILURE);
	i = -1;
	while (++i < args->nbr_of_philo)
	{
		if (pthread_join(philos[i].t_id, NULL) != 0)
		{
			destroy(args, forks, philos);
			return (panic(THREAD_JOIN_ERR));
		}
	}
	return (true);
}
