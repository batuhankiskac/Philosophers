/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:12:37 by bkiskac           #+#    #+#             */
/*   Updated: 2025/02/14 22:22:17 by bkiskac          ###   ########.fr       */
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

static int	*philo_routine(void *arg)
{

}

int	dinner_start(t_program *prog)
{
	int	i;

	i = -1;
	while (++i < prog->philo_num)
	{
		if (pthread_create(&prog->philos[i].thread, NULL,
			philo_routine, (void *)&prog->philos[i]) != 0)
			return (ERROR);
	}
	i = -1;
	while (++i < prog->philo_num)
	{
		if (pthread_join(prog->philos[i].thread, NULL) != 0)
			return (ERROR);
	}
	return (0);
}
