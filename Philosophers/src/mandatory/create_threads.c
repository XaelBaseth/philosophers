/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:41:12 by acharlot          #+#    #+#             */
/*   Updated: 2023/06/29 12:34:14 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers.h"

static void	*supervisor(void *philos)
{
	t_philo	*casted;
	int		i;

	casted = (t_philo *)philos;
	while (!all_ate_n_times(casted))
	{
		i = -1;
		while (++i < casted->args->nbr_of_philo)
		{
			pthread_mutex_lock(&casted[i].can_die);
			if (starved(&casted[i]))
			{
				monitoring(casted, DEAD);
				casted->args->someone_died = true;
				pthread_mutex_unlock(&casted[i].can_die);
				pthread_mutex_unlock(&casted[i].args->monitoring_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&casted[i].can_die);
			pthread_mutex_lock(&casted[i].eaten_meals_mutex);
			if (casted[i].eaten_meals == casted->args->must_eat_times)
				casted->args->satisfied_philos += 1;
			pthread_mutex_unlock(&casted[i].eaten_meals_mutex);
		}
	}
	printf("Every Philosopher had %d meals!\n", casted->args->must_eat_times);
	return (NULL);
}


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
