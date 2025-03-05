/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:09:04 by bkiskac           #+#    #+#             */
/*   Updated: 2025/03/05 21:53:26 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clean_up(t_program *prog)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&prog->meal_lock);
	pthread_mutex_destroy(&prog->write_lock);
	while (++i < prog->philo_num)
	{
		if (prog->philos[i].r_fork)
		{
			pthread_mutex_destroy(prog->philos[i].r_fork);
			free(prog->philos[i].r_fork);
		}
	}
	if (prog->philos)
		free(prog->philos);
	free(prog);
	return (0);
}
