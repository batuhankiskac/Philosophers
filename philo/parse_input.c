/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:00:51 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/30 21:15:39 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long parse_long(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '0' && *str <= '9'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	result *= sign;
	if (result < 0 || result > INT_MAX)
		return_error("Please enter valid input.");
	return (result);
}

void	parse_input(t_data *data, char *argv[])
{
	data->philo_count = parse_long(argv[1]);
	data->time_to_die = parse_long(argv[2]) * 1e3;
	data->time_to_eat = parse_long(argv[3]) * 1e3;
	data->time_to_sleep = parse_long(argv[4]) * 1e3;
	if (data->time_to_die < 6e4 || data->time_to_eat < 6e4
		|| data->time_to_sleep < 6e4)
		return_error("Use timestamps major than 60ms");
	if (argv[5])
		data->max_meal = parse_long(argv[5]);
	else
		data->max_meal = -1;
}
