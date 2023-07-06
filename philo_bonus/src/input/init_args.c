/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:34:28 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/06 11:57:56 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers_bonus.h"

/*	Unlinks and opens "/forks", "/meal" and "/print" named semaphore*/
static void	open_sems(t_args *args)
{
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_MEAL);
	sem_unlink(SEM_PRINT);
	args->sem_forks = sem_open(SEM_FORKS, O_CREAT, S_IRWXU, 
		args->nbr_of_philo);
	if (args->sem_forks == SEM_FAILED)
		panic(SEMOPEN_ERR);
	args->sem_meal = sem_open(SEM_MEAL, O_CREAT, S_IRWXU, 1);
	if (args->sem_meal == SEM_FAILED)
	{
		sem_close(args->sem_forks);
		panic(SEMOPEN_ERR);
	}
	args->sem_print = sem_open(SEM_PRINT, O_CREAT, S_IRWXU, 1);
	if (args->sem_print == SEM_FAILED)
	{
		sem_close(args->sem_forks);
		sem_close(args->sem_meal);
		panic(SEMOPEN_ERR);
	}
}

/*	Initialize the arguments given as parameters. */
t_args	init_args(char **argv)
{
	t_args args;

	args.nbr_of_philo = ft_atoi(argv[1]);
	args.time_to_die = ft_atoi(argv[2]);
	args.time_to_eat = ft_atoi(argv[3]);
	args.time_to_sleep = ft_atoi(argv[4]);
	args.must_eat_times = -1;
	if (argv[5])
		args.must_eat_times = ft_atoi(argv[5]);
	if (args.must_eat_times == 0)
	{
		printf("Philosophers do no need to eat.\n");
		exit(EXIT_SUCCESS);
	}
	open_sems(&args);
	return (args);
}