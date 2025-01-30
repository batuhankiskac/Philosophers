/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:49:36 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/30 18:03:25 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char  *argv[])
{
	t_philo	philo;

	if (argc == 5 || argc == 6)
	{
		parse_input(&philo);
		data_init(&philo);
		dinner_start(&philo, argv);
		cleanup_data(&philo);
		return (0);
	}
	else
	{
		printf(ERR_ARGS);
		return (-1);
	}
}

