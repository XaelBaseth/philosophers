/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:08:34 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/06 12:33:09 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers_bonus.h"

/*	Cleanly close the semaphores. */
void	destroy(t_args *args, t_philo *philo_array)
{
	sem_close(args->sem_forks);
	sem_close(args->sem_meal);
	sem_close(args->sem_print);
	free(philo_array);
	philo_array = NULL;
}