/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:12:37 by bkiskac           #+#    #+#             */
/*   Updated: 2025/03/01 12:52:26 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->prog->philo_num == 1)
	{
		single_philo_routine(philo);
		return (NULL);
	}
	while (!philo->prog->end_sim)
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
