/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_ate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:10:07 by acharlot          #+#    #+#             */
/*   Updated: 2023/06/30 10:27:23 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers.h"

bool	all_ate_n_times(t_philo *philo)
{
	bool result;
	
	pthread_mutex_lock(&philo->args->satisfied_philo_mutex);
	result = philo->args->satisfied_philos == philo->args->nbr_of_philo;
	pthread_mutex_unlock(&philo->args->satisfied_philo_mutex);
	return (result);
}
