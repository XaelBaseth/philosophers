#include "../../inc/philosophers.h"

int	no_args_outside_limits(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (!((ft_atoi_long(argv[i])) > INT_MAX) || !(ft_atoi_long(argv[i]) < INT_MIN))
			return (TRUE);
	}
	return (FALSE);
}

int	right_amount_of_args(int argc)
{
	if (argc < 5 || argc > 6)
		return (ERROR);
	else
		return (SUCCESS);
}

int	arguments_are_correct(int argc, char **argv)
{
	if (right_amount_of_args(argc) && all_args_are_numbers(argv))
	{
		if (no_args_outside_limits(argv))
			return (TRUE);
		return (print_limits_error(), FALSE);
	}
	return (print_right_syntax(), FALSE);
}