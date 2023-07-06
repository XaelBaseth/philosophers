/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:49:43 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/06 12:33:18 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers_bonus.h"

/*	Ensure that every philosophers' meals is counted. */
void	*eats_checker(void	*philos)
{
	t_philo *casted;
	int		satisfied_philos;
	int		i;

	casted = (t_philo *)philos;
	satisfied_philos = 0;
	while (satisfied_philos < casted->args->nbr_of_philo)
	{
		i = 0;
		while (i < casted->args->nbr_of_philo)
		{
			sem_wait(casted->args->sem_meal);
			i++;
		}
		satisfied_philos++;
	}
	printf("\033[32mEvery Philosopher ate %d meals!\n\033[0m",
		casted->args->must_eat_times);
	sem_wait(casted->args->sem_print);
	end_processes(philos);
	return (NULL);
}

/*	Create the thread that will checks the meals. */
void	create_eats_checker(t_args *args, t_philo *philos)
{
	if (pthread_create(&args->eats_checker_tid, NULL, eats_checker,
		(void *)philos) != 0)
		destroy(args, philos);
	pthread_detach(args->eats_checker_tid);
}