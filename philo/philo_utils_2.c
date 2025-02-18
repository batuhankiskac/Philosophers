/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:37:48 by bkiskac           #+#    #+#             */
/*   Updated: 2025/02/18 19:38:02 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	single_philo_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_unlock(philo->l_fork);
	ft_usleep(philo->prog->time_to_die, philo->dead);
}

int	take_forks(t_philo *philo)
{
	if (philo->is_even)
	{
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork");
	}
	return (0);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

int	eat(t_philo *philo)
{
	print_status(philo, "is eating");
	philo->last_meal = get_current_time();
	if (ft_usleep(philo->prog->time_to_eat, philo->dead) == ERROR)
		return (ERROR);
	philo->meals_eaten++;
	return (0);
}

int	sleep_and_think(t_philo *philo)
{
	print_status(philo, "is sleeping");
	if (ft_usleep(philo->prog->time_to_sleep, philo->dead) == ERROR)
		return (ERROR);
	print_status(philo, "is thinking");
	if (ft_usleep(100, philo->dead) == ERROR)
		return (ERROR);
	return (0);
}
