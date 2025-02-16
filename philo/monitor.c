/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:01:37 by bkiskac           #+#    #+#             */
/*   Updated: 2025/02/16 16:21:40 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_deaths(t_program *prog)
{
	int		i;
	size_t	current_time;

	i = -1;
	current_time = get_current_time();
	while (++i < prog->philo_num)
	{
		pthread_mutex_lock(&prog->meal_lock);
		if (current_time - prog->philos[i].last_meal > prog->time_to_die)
		{
			pthread_mutex_unlock(&prog->meal_lock);
			pthread_mutex_lock(&prog->write_lock);
			printf("%zu %d died\n", current_time - prog->philos[i].start_time,
				prog->philos[i].id);
			pthread_mutex_unlock(&prog->write_lock);
			return (1);
		}
		pthread_mutex_unlock(&prog->meal_lock);
	}
	return (0);
}

static int	check_meals(t_program *prog)
{
	int	i;
	int	done;

	i = -1;
	done = 1;
	while (++i < prog->philo_num)
	{
		pthread_mutex_lock(prog->philos[i].meal_lock);
		if (prog->philos[i].meals_eaten < prog->max_meals)
		{
			done = 0;
			pthread_mutex_unlock(prog->philos[i].meal_lock);
			break ;
		}
		pthread_mutex_unlock(prog->philos[i].meal_lock);
	}
	return (done);
}

int	monitor(t_program *prog)
{
	while (!(prog->dead_flag))
	{
		if (check_deaths(prog))
		{
			prog->dead_flag = 1;
			break ;
		}
		if (prog->max_meals != -1 && check_meals(prog))
		{
			pthread_mutex_lock(&prog->write_lock);
			printf("All philosophers have eaten %d times\n", prog->max_meals);
			pthread_mutex_unlock(&prog->write_lock);
			prog->dead_flag = 1;
			break ;
		}
		ft_usleep(1);
	}
	return (0);
}
