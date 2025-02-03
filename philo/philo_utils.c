/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:05:49 by bkiskac           #+#    #+#             */
/*   Updated: 2025/02/03 16:20:17 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_handle(pthread_mutex_t *mutex, t_opcode opcode)
{
	if (opcode == LOCK)
	{
		if (pthread_mutex_lock(mutex))
			return (ERROR);
	}
	else if (opcode == UNLOCK)
	{
		if (pthread_mutex_unlock(mutex))
			return (ERROR);
	}
	else if (opcode == INIT)
	{
		if (pthread_mutex_init(mutex, NULL))
			return (ERROR);
	}
	else if (opcode == DESTROY)
	{
		if (pthread_mutex_destroy(mutex))
			return (ERROR);
	}
	else
		return (ERROR);
	return (0);
}
