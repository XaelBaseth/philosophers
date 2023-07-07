/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:52:14 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/07 10:30:16 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_args	args;
	t_philo	*philos;

	if (!validate_args(argc, argv))
		return (EXIT_FAILURE);
	args = init_args(argv);
	philos = init_philos(&args);
	create_processes(&args, philos);
	destroy(&args, philos);
	return (EXIT_SUCCESS);
}