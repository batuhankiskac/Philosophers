/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:05:49 by bkiskac           #+#    #+#             */
/*   Updated: 2025/02/11 17:30:18 by bkiskac          ###   ########.fr       */
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

int	thread_handle(pthread_t thread, t_opcode opcode, void *(*func)(void *))
{
	if (opcode == CREATE)
	{
		if (pthread_create(&thread, NULL, func, NULL))
			return (ERROR);
	}
	else if (opcode == JOIN)
	{
		if (pthread_join(thread, NULL))
			return (ERROR);
	}
	else if (opcode == DETACH)
	{
		if (pthread_detach(thread))
			return (ERROR);
	}
	else
		return (ERROR);
}

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
