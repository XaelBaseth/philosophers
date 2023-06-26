#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

//VARIABLE
# define TRUE		1
# define SUCCESS 	1
# define FALSE		0
# define ERROR		0
# define FAILURE	0

//LIBRAIRY
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

//STRUCTURES
typedef	struct s_philo
{
	int				id;
	int				last_meal;
	int				is_eating;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				number_of_meals;
	pthread_t		thread_id;
	struct s_general	*general;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
}					philo_t;

typedef struct s_general
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meals;
	int				starting_time;
	int				philosopher_dead;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	philo_t			*philosophers;
}					general_t;


//FUNCTIONS
//main
int	structs(general_t *general, char **argv);
void	unlock_philosophers_mutex(general_t *philosophers);
int	mutex(general_t *general);
int	initialise_philosophers(general_t *general);
//philosopher_actions
int	philosopher_is_dead(philo_t *philosophers);
void	philosophers_is_thinking(philo_t *philosophers);
void	philosophers_is_sleeping(philo_t *philosophers);
void	philosopher_is_eating(philo_t *philosophers);
int	philosopher_takes_forks(philo_t *philosophers);
//philosophers_monitoring
void	*begin_monitoring(void *arg);
void	free_philosophers(general_t *philosophers);
//philosophers_routine
void	begin_philosophers_routine(general_t *data);
void	join_threads(general_t *data);
void	*philosophers_routine(void	*arguments);
//utils
void	print_right_syntax(void);
void	print_limits_error(void);
long	ft_atoi_long(const char *str);
int	ft_atoi(const char *str);
//utils_2
void	print_message(char *str, philo_t *philosopher);
int	get_time(void);
void	ft_sleep(int time, philo_t *philosophers);
//arguments_char
int	arguments_are_correct(int argc, char **argv);
//arguments_num
int	all_args_are_numbers(char **argv);
#endif