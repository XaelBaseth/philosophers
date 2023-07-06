/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:35:13 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/06 12:33:23 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers_bonus.h"

/*	Unlink and opens "/lock_death" named semaphore. */
static bool	open_sem(t_philo *philo)
{
	sem_unlink(SEM_LOCK_DEATH);
	philo->sem_lock_death = sem_open(SEM_LOCK_DEATH, O_CREAT, S_IRWXU, 1);
	if (philo->sem_lock_death == SEM_FAILED)
		return (false);
	return (true);
}

/*	Initialize the philosopher with the corresponding structure. */
t_philo	*init_philos(t_args *args)
{
	t_philo	*philos;
	int		i;

	philos = malloc(args->nbr_of_philo * sizeof(t_philo));
	if (!philos)
		panic(MALLOC_ERR);
	i = 0;
	while (i < args->nbr_of_philo)
	{
		philos[i].philo_nbr = i + 1;
		philos[i].last_meal_time = get_time();
		if (!open_sem(&philos[i]))
		{
			destroy(args, philos);
			panic(SEMOPEN_ERR);
		}
		philos[i].args = args;
		i++;
	}
	return (philos);
}