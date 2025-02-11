/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:58:42 by bkiskac           #+#    #+#             */
/*   Updated: 2025/02/11 14:21:33 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_forks(t_data *data)
{
	int	i;

	i = -1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
		return (ERROR);
	while (++i < data->philo_count)
	{
		if (mutex_handle(&data->forks[i], INIT) == ERROR)
		{
			while (--i >= 0)
				mutex_handle(&data->forks[i], DESTROY);
			free(data->forks);
			return (ERROR);
		}
	}
	return (0);
}

static int	init_print_mutex(t_data *data)
{
	int	i;

	i = -1;
	if (mutex_handle(&data->print_lock, INIT) == ERROR)
	{
		while (++i < data->philo_count)
			mutex_handle(&data->forks[i], DESTROY);
		free(data->forks);
		return (ERROR);
	}
	return (0);
}

static int	init_philosophers(t_data *data)
{
	int	i;

	i = -1;
	data->philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philos)
		return (ERROR);
	while (++i < data->philo_count)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal = 0;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->philo_count];
		data->philos[i].data = data;
		data->philos[i].is_full = false;
	}
	return (0);
}

int	data_init(t_data *data)
{
	int	i;

	i = -1;
	if (init_forks(data) == ERROR)
		return (ERROR);
	if (init_print_mutex(data) == ERROR)
		return (ERROR);
	if (init_philosophers(data) == ERROR)
	{
		while (++i < data->philo_count)
			mutex_handle(&data->forks[i], DESTROY);
		mutex_handle(&data->print_lock, DESTROY);
		free(data->forks);
		free(data->philos);
		return (ERROR);
	}
	data->start_time = get_time();
	data->is_dead = false;
	return (0);
}
