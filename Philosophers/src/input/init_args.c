/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:14:20 by acharlot          #+#    #+#             */
/*   Updated: 2023/06/28 13:14:25 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers.h"

#define ARGS_0 "nbr_of_philosophers and must_eat_times must be bigger \
than 0.\n"

bool	init_args(t_args *args, char **argv)
{
	args->nbr_of_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->must_eat_times = -1;
	if (argv[5])
		args->must_eat_times = ft_atoi(argv[5]);
	if (args->nbr_of_philo == 0 || args->must_eat_times == 0)
	{
		printf(ARGS_0);
		return (false);
	}
	if (pthread_mutex_init(&args->monitoring_mutex, NULL) != 0)
	{
		panic(MUTEX_INIT_ERR);
		return (false);
	}
	args->satisfied_philos = 0;
	args->someone_died = false;
	return (true);
}
