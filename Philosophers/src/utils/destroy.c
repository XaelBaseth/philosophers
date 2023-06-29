/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:38:57 by acharlot          #+#    #+#             */
/*   Updated: 2023/06/28 13:11:58 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers.h"

void	destroy(t_args *args, pthread_mutex_t *forks, t_philo *philos)
{
	int	i;

	pthread_mutex_destroy(&args->monitoring_mutex);
	if (forks)
	{
		i = 0;
		while (i < args->nbr_of_philo)
		{
			pthread_mutex_destroy(&philos[i].can_die);
			pthread_mutex_destroy(&forks[i]);
			philos[i].left_fork = NULL;
			philos[i].right_fork = NULL;
			i++;
		}
		free(forks);
		forks = NULL;
	}
	if (philos)
	{
		free(philos);
		philos = NULL;
	}
}
