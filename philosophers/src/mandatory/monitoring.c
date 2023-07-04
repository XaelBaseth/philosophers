/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:41:28 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/04 11:20:40 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers.h"

#define TAKE_FORK_STR "has taken a fork.\n"
#define DROP_FORK_STR "has dropped a fork.\n"
#define EAT_STR "is eating.\n"
#define THINK_STR "is thinking.\n"
#define SLEEP_STR "is sleeping.\n"
#define DEAD_STR "died.\n"

/*	Monitors and printouts the according message for every philosophers 
	actions. */
void	monitoring(t_philo *philo, t_event_id event)
{
	suseconds_t	timestamp;
	const char	*events[6] = {DEAD_STR, EAT_STR, THINK_STR,
		SLEEP_STR, TAKE_FORK_STR, DROP_FORK_STR};

	if (philo->args->someone_died || all_ate_n_times(philo))
		return ;
	timestamp = get_time() - philo->start_time;
	pthread_mutex_lock(&philo->args->monitoring_mutex);
	printf("%ldms\t%d %s", timestamp, philo->philo_nbr, events[event]);
	pthread_mutex_unlock(&philo->args->monitoring_mutex);
}
