/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_processes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:21:15 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/06 10:21:38 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers_bonus.h"

/*	Put an end to the process. */
void	end_processes(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->args->nbr_of_philo)
		kill(philo[i++].pid, SIGTERM);
}