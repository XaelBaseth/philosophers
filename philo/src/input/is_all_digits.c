/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_all_digits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:14:01 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/10 12:30:41 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers.h"

/*	Helper function in order to make sure that the given input is a number. */
static bool	isdigit_(char c)
{
	if ((c >= '0' && c <= '9'))
		return (true);
	return (false);
}

static int	is_int(int i)
{
	if (i >= INT_MIN && i < INT_MAX)
		return (false);
	return (true);
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
			if ((isdigit_(argv[i][j])) && (is_int((int)argv[i][j])) == false)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
