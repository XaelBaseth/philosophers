/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 08:17:56 by acharlot          #+#    #+#             */
/*   Updated: 2023/06/28 14:30:40 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers.h"

static inline bool	validate_args(int argc, char **argv)
{
	if ((argc != 5 && argc != 6) || !is_all_digits(argv))
	{
		panic(INVALID_ARGS_ERR);
		return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_args			args;
	pthread_mutex_t	*forks;
	t_philo			*philos;

	if (!validate_args(argc, argv) || !init_args(&args, argv))
		return (EXIT_FAILURE);
	forks = init_forks(&args);
	philos = init_philos(&args, forks);
	if (!create_threads(&args, philos, forks))
		return (EXIT_FAILURE);
	destroy(&args, forks, philos);
	return (EXIT_SUCCESS);
}
