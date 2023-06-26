#include "../../inc/philosophers.h"

int	string_is_numeric(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			return (TRUE);
	}
	return (FALSE);
}

int	all_args_are_numbers(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (string_is_numeric(argv[i]))
			return (TRUE);
		else
			return (FALSE);
	}
	return (TRUE);
}