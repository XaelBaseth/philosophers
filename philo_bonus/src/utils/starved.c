/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starved.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:06:43 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/06 10:19:55 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers_bonus.h"

/*	Checks if a philosophers starved to death. */
bool	starved(t_philo *philo)
{
	return (((get_time() - philo->last_meal_time)
			>= philo->args->time_to_die));
}