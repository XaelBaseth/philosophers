/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:31:56 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/06 12:35:06 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers_bonus.h"

/*	Wait and kills all philosophers processes. */
void	wait_child(t_philo *philo)
{
	int	status;

	waitpid(-1, &status, 0);
	if (WIFEXITED(status) || WIFSIGNALED(status))
		end_processes(philo);
}

/*	Thread that watch the philosophers' activities. */
static void	*supervisor(void *philo)
{
	t_philo *casted;

	casted = (t_philo *)philo;
	while (true)
	{
		sem_wait(casted->sem_lock_death);
		if (starved(casted))
		{
			monitoring(casted, DEAD);
			sem_wait(casted->args->sem_print);
			//return (NULL);
			printf("\033[31mA philosopher died. End of experiment.\n\033[0m");
			exit(EXIT_SUCCESS);
		}
		sem_post(casted->sem_lock_death);
	}
	return (NULL);
}

/*	Create the supervisor thread and makes philosophers process enter
	routine. */
static void	create_philo(t_philo *philo)
{
	pthread_t	supervisor_tid;
	
	pthread_create(&supervisor_tid, NULL, supervisor, (void *)philo);
	pthread_detach(supervisor_tid);
	routine(philo);
	exit(EXIT_SUCCESS);
}
/*	Create the philosophers processes.*/
void	create_processes(t_args *args, t_philo *philos)
{
	int	i;

	i = 0;
	if (args->must_eat_times > 0)
		create_eats_checker(args, philos);
	while (i < args->nbr_of_philo)
	{
		philos[i].start_time = get_time();
		philos[i].pid = fork();
		if (philos[i].pid == -1)
		{
			destroy(args, philos);
			panic(FORK_ERR);
		}
		if (philos[i].pid == 0)
			create_philo(&philos[i]);
		usleep(100);
		i++;
	}
	wait_child(philos);
}
