/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_all_digits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:14:01 by acharlot          #+#    #+#             */
/*   Updated: 2023/06/30 14:46:01 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers.h"

/*	Helper function in order to make sure that the given input is a number. */
static bool	isdigit_or_signal(char c)
{
	if ((c >= '0' && c <= '9'))
		return (true);
	return (false);
}

/*	Makes sure that the given input is a number. */
bool	is_all_digits(char **argv)
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
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
