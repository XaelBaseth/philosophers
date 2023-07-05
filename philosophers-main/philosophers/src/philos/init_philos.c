/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:41:56 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/04 11:18:40 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers.h"

/*	 Helper function that initialize the structures t_philos and t_args. */
static void	initialize_philo(t_philo *philos, t_args *args, pthread_mutex_t
	*forks_array, int i)
{
	philos[i].philo_nbr = i + 1;
	philos[i].eaten_meals = 0;
	philos[i].left_fork = &forks_array[i];
	philos[i].right_fork = &forks_array[(i + 1) % args->nbr_of_philo];
	philos[i].last_meal_time = get_time();
	if (pthread_mutex_init(&philos[i].can_die, NULL) != 0)
	{
		destroy(args, forks_array, philos);
		panic(MUTEX_INIT_ERR);
	}
	if (pthread_mutex_init(&philos[i].eaten_meals_mutex, NULL) != 0)
	{
		destroy(args, forks_array, philos);
		panic(MUTEX_INIT_ERR);			
	}
	if (pthread_mutex_init(&philos[i].satisfied_philo_mutex, NULL) != 0)
	{
		destroy(args, forks_array, philos);
		panic(MUTEX_INIT_ERR);
	}
	philos[i].args = args;
}

/*	Initialize the correct structures. */
t_philo	*init_philos(t_args *args, pthread_mutex_t *forks_array)
{
	t_philo	*philos;
	int		i;

	philos = malloc(args->nbr_of_philo * sizeof(t_philo));
	if (!philos)
	{
		destroy(args, forks_array, NULL);
		panic(MALLOC_ERR);
	}
	i = -1;
	while (++i < args->nbr_of_philo)
		initialize_philo(philos, args, forks_array, i);
	return (philos);
}
