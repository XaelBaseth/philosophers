/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:34:22 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/07 10:32:18 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers_bonus.h"

/*	Helper function in order to make sure that the given input is a number. */
static bool	isdigit_or_signal(char c)
{
	if ((c >= '0' && c <= '9'))
		return (true);
	return (false);
}

/*	Makes sure that the given input is a number. */
static bool	is_all_digits(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (isdigit_or_signal(argv[i][j]) == false)
			{
				panic("Not all arguments are numbers.\n");
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

/*	Validate the arguments given as parameter. */
bool	validate_args(int argc, char **argv)
{
	if ((argc != 5 && argc != 6))
	{
		panic("Invalide number of arguments.\n");
		return (false);
	}
	if (!is_all_digits(argv))
		return (false);
	return (true);
}