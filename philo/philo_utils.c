/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:23:11 by bkiskac           #+#    #+#             */
/*   Updated: 2025/02/11 22:07:23 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, char *status)
{
	long	time;

	pthread_mutex_lock(&philo->data->print_lock);
	time = get_time(philo->data);
	printf("%ld %d %s\n", time, philo->id, status);
	pthread_mutex_unlock(&philo->data->print_lock);
}

void	clean_up(t_data *data)
{
	int	i;

	if (data->forks)
	{
		i = -1;
		while (++i < data->philo_count)
			pthread_mutex_destroy(&data->forks[i]);
		free(data->forks);
	}
	if (data->philos)
	{
		i = -1;
		while (++i < data->philo_count)
			pthread_mutex_destroy(&data->philos[i].meal_lock);
		free(data->philos);
	}
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->meal_lock);
	
}
