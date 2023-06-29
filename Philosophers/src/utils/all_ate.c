/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_ate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:10:07 by acharlot          #+#    #+#             */
/*   Updated: 2023/06/28 13:52:34 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers.h"

bool	all_ate_n_times(t_philo *philo)
{
	return (philo->args->satisfied_philos == philo->args->nbr_of_philo);
}
