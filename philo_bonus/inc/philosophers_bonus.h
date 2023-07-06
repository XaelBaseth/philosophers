#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

//LIBRAIRY
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <semaphore.h>
# include <signal.h>
# include <memory.h>
# include <stdbool.h>
# include <limits.h>

//CONSTANT
# define MICROSEC 1000


//SEMAPHORE NAMES
# define SEM_FORKS "/forks"
# define SEM_MEAL "/meal"
# define SEM_PRINT "/print"
# define SEM_LOCK_DEATH "/lock_death"

//ERROR MESSAGES
# define SEMOPEN_ERR "Failed to open a semaphore"
# define FORK_ERR "Failed to fork()"
# define MALLOC_ERR "malloc() failed to allocate memory"
# define THREAD_CREATE_ERR "Failes to create a thread"
# define THREAD_JOIN_ERR "Failes to join a thread"

//STRUCTURES
typedef struct s_args
{
	int			nbr_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat_times;
	sem_t		*sem_forks;
	sem_t		*sem_meal;
	sem_t		*sem_print;
	pthread_t	eats_checker_tid;
}				t_args;

typedef struct s_philo
{
	int			philo_nbr;
	pid_t		pid;
	suseconds_t	last_meal_time;
	suseconds_t	start_time;
	sem_t		*sem_lock_death;
	t_args		*args;
}				t_philo;

typedef enum	e_event_id
{
	DEAD,
	EAT,
	THINK,
	SLEEP,
	FORK,
	DROP,
}				t_event_id;


//FUNCTIONS
/*	utils	*/
bool		starved(t_philo *philo);
int			panic(char *error_msg);
int			ft_atoi(char *str);
suseconds_t	get_time(void);
void		end_processes(t_philo *philo);
void		destroy(t_args *args, t_philo *philo_array);
/*	mandatory	*/
void		monitoring(t_philo *philo, t_event_id event);
void		create_processes(t_args *args, t_philo *philos);
void		wait_child(t_philo *philo);
void		create_eats_checker(t_args *args, t_philo *philos);
void		*eats_checker(void	*philos);
/*	input	*/
t_args		init_args(char **argv);
bool		validate_args(int argc, char **argv);
/*	philos	*/
void		routine(t_philo *philo);
t_philo		*init_philos(t_args *args);

#endif