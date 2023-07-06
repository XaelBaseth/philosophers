/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:17:13 by acharlot          #+#    #+#             */
/*   Updated: 2023/07/06 10:20:20 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosophers_bonus.h"

/*	Print out an error message. */
int	panic(char *error_msg)
{
	printf("Error: %s", error_msg);
	return (EXIT_FAILURE);
}
