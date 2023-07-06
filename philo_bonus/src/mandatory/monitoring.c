/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:22:46 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/06 10:29:03 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers_bonus.h"

#define TAKE_FORK_STR "has taken a fork.\n"
#define DROP_FORK_STR " has dropped a fork.\n"
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
	
	sem_wait(philo->args->sem_print);
	timestamp = get_time() - philo->start_time;
	printf("\033[33m%ldms\t\033[0m%d %s", timestamp, philo->philo_nbr, events[event]);
	sem_post(philo->args->sem_print);
}