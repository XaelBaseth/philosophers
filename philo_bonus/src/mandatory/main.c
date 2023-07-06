/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:52:14 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/06 12:33:05 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_args	args;
	t_philo	*philos;

	validate_args(argc, argv);
	args = init_args(argv);
	philos = init_philos(&args);
	create_processes(&args, philos);
	destroy(&args, philos);
	return (EXIT_SUCCESS);
}