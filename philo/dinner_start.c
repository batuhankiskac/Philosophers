/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:12:37 by bkiskac           #+#    #+#             */
/*   Updated: 2025/02/16 16:32:34 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(philo->write_lock);
	printf("%zu %d %s\n", get_current_time() - philo->start_time,
		philo->id, status);
	pthread_mutex_unlock(philo->write_lock);
}

static void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!(*philo->dead))
	{
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		print_status(philo, "has taken a fork");
		print_status(philo, "is eating");
		philo->last_meal = get_current_time();
		ft_usleep(philo->prog->time_to_eat);
		philo->meals_eaten++;
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		if (philo->prog->max_meals != -1
			&& philo->meals_eaten >= philo->prog->max_meals)
			break ;
		print_status(philo, "is sleeping");
		ft_usleep(philo->prog->time_to_sleep);
		print_status(philo, "is thinking");
		ft_usleep(100);
	}
	return (NULL);
}

int	start_threads(t_program *prog)
{
	int	i;

	i = -1;
	while (++i < prog->philo_num)
	{
		if (pthread_create(&prog->philos[i].thread, NULL,
				philo_routine, (void *)&prog->philos[i]) != 0)
			return (ERROR);
	}
	return (0);
}

int	join_threads(t_program *prog)
{
	int	i;

	i = -1;
	while (++i < prog->philo_num)
	{
		if (pthread_join(prog->philos[i].thread, NULL) != 0)
			return (ERROR);
	}
	return (0);
}
