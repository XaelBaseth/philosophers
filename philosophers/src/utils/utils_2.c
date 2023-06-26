#include "../../inc/philosophers.h"

void	print_message(char *str, philo_t *philosopher)
{
	if (!philosopher_is_dead(philosopher))
	{
		pthread_mutex_lock(&philosopher->general->mutex);
		printf("%dms	 %d %s\n", get_time()
			- philosopher->general->starting_time, philosopher->id, str);
		pthread_mutex_unlock(&philosopher->general->mutex);
	}
}

int	get_time(void)
{
	static struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_sleep(int time, philo_t *philosophers)
{
	int	start;

	start = get_time();
	while ((get_time() - start) < time
		&& philosopher_is_dead(philosophers) == FALSE)
		usleep(50);
}