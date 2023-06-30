/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starved.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:10:20 by acharlot          #+#    #+#             */
/*   Updated: 2023/06/30 16:30:39 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers.h"

/*	Function that check if a philosopher starved to death. */
bool	starved(t_philo *philo)
{
	return (((get_time() - philo->last_meal_time)
			>= philo->args->time_to_die));
}
