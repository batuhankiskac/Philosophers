/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:56:11 by bkiskac           #+#    #+#             */
/*   Updated: 2025/02/11 21:07:32 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_philos(t_data *data)
{
	int	i;

	i = -1;
	data->philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philos)
		return (ERROR);
	while (++i < data->philo_count)
	{
		data->philos[i].id = i + 1;
		data->philos[i].last_meal = 0;
		data->philos[i].meals_eaten = 0;
		data->philos[i].left_fork_id = i;
		data->philos[i].right_fork_id = (i + 1) % data->philo_count;
		data->philos[i].data = data;
	}
	return (0);
}

int	data_init(t_data *data)
{
	
	gettimeofday(&data->start_time, NULL);
	data->end_sim = false;
	return (0);
}
