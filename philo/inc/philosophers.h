/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 08:22:29 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/07 13:27:03 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

//CONSTANT
# define MICROSEC 1000


//ERROR MESSAGE
# define INVALID_ARGS_ERR "Invalid arguments"
# define THREAD_CREATE_ERR "Failed to create a thread"
# define THREAD_JOIN_ERR "Failed to join a thread"
# define MALLOC_ERR "malloc() failed to allocated memory"
# define MUTEX_INIT_ERR "Failed to initialize mutex"

//LIBRAIRY
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <memory.h>
# include <stdbool.h>

//STRUCTURES
typedef struct s_args
{
	int				nbr_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_times;
	pthread_mutex_t	monitoring_mutex;
	int				satisfied_philos;
	pthread_mutex_t	satisfied_philo_mutex;
	bool			someone_died;
	pthread_mutex_t	someone_died_mutex;
}					t_args;

typedef struct s_philo
{
	int				philo_nbr;
	int				eaten_meals;
	pthread_mutex_t	eaten_meals_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	suseconds_t		last_meal_time;
	pthread_t		t_id;
	suseconds_t		start_time;
	pthread_mutex_t	can_die;
	t_args			*args;
}					t_philo;

typedef enum e_event_id
{
	DEAD,
	EAT,
	THINK,
	SLEEP,
	FORK,
	DROP,
}		t_event_id;

//FUNCTIONS
//utils
int				panic(char *error_msg);
pthread_mutex_t	*init_forks(t_args *args);
void			destroy(t_args *args, pthread_mutex_t *forks, t_philo *philos);
int				ft_atoi(char *str);
suseconds_t		get_time(void);
bool			all_ate_n_times(t_philo *philo);
bool			starved(t_philo *philo);
//create_threads
bool			create_threads(t_args *args, t_philo *philos,
					pthread_mutex_t *forks);
//monitoring
void			monitoring(t_philo *philo, t_event_id event);
//philos
t_philo			*init_philos(t_args *args, pthread_mutex_t *forks_array);
void			*routine(void *philo);
//input
bool			is_all_digits(char **argv);
bool			init_args(t_args *args, char **argv);

#endif