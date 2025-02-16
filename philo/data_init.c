/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:52:13 by bkiskac           #+#    #+#             */
/*   Updated: 2025/02/16 18:30:13 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_init(t_philo *philo, t_program *prog, int id)
{
	philo->id = id;
	philo->meals_eaten = 0;
	philo->start_time = get_current_time();
	philo->last_meal = philo->start_time;
	philo->dead = &prog->dead_flag;
	philo->write_lock = &prog->write_lock;
	philo->dead_lock = &prog->dead_lock;
	philo->meal_lock = &prog->meal_lock;
	philo->r_fork = malloc(sizeof(pthread_mutex_t));
	if (!philo->r_fork)
		return (ERROR);
	if (pthread_mutex_init(philo->r_fork, NULL) != 0)
		return (ERROR);
	return (0);
}

int	data_init(t_program *prog)
{
	int	i;

	prog->dead_flag = 0;
	i = -1;
	if (pthread_mutex_init(&prog->dead_lock, NULL) != 0
		|| pthread_mutex_init(&prog->meal_lock, NULL) != 0
		|| pthread_mutex_init(&prog->write_lock, NULL) != 0)
		return (ERROR);
	prog->philos = malloc(sizeof(t_philo) * prog->philo_num);
	if (!prog->philos)
		return (ERROR);
	while (++i < prog->philo_num)
		if (philo_init(&prog->philos[i], prog, i + 1) == ERROR)
			return (ERROR);
	i = -1;
	while (++i < prog->philo_num)
	{
		if (i == 0)
			prog->philos[i].l_fork = prog->philos[prog->philo_num - 1].r_fork;
		else
			prog->philos[i].l_fork = prog->philos[i - 1].r_fork;
	}
	return (0);
}
