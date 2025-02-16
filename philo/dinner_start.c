/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:12:37 by bkiskac           #+#    #+#             */
/*   Updated: 2025/02/16 20:07:36 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	single_philo_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_unlock(philo->l_fork);
	ft_usleep(philo->prog->time_to_die, philo->dead);
}

static int	take_forks(t_philo *philo)
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

static void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

static int	eat(t_philo *philo)
{
	print_status(philo, "is eating");
	philo->last_meal = get_current_time();
	if (ft_usleep(philo->prog->time_to_eat, philo->dead) == ERROR)
		return (ERROR);
	philo->meals_eaten++;
	return (0);
}

static int	sleep_and_think(t_philo *philo)
{
	print_status(philo, "is sleeping");
	if (ft_usleep(philo->prog->time_to_sleep, philo->dead) == ERROR)
		return (ERROR);
	print_status(philo, "is thinking");
	if (ft_usleep(100, philo->dead) == ERROR)
		return (ERROR);
	return (0);
}

static void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->prog->philo_num == 1)
	{
		single_philo_routine(philo);
		return (NULL);
	}
	while (!(*philo->dead))
	{
		if (take_forks(philo) == ERROR)
			break ;
		if (eat(philo) == ERROR)
		{
			release_forks(philo);
			break ;
		}
		release_forks(philo);
		if (philo->prog->max_meals != -1
			&& philo->meals_eaten >= philo->prog->max_meals)
			break ;
		if (sleep_and_think(philo) == ERROR)
			break ;
	}
	return (NULL);
}

int	start_threads(t_program *prog)
{
	int	i;

	i = -1;
	while (++i < prog->philo_num)
	{
		prog->philos[i].prog = prog;
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
