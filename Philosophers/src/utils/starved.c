/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starved.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:10:20 by acharlot          #+#    #+#             */
/*   Updated: 2023/06/28 13:14:34 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers.h"

bool	starved(t_philo *philo)
{
	return (((get_time() - philo->last_meal_time)
			>= philo->args->time_to_die));
}
