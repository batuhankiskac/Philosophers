/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:27:42 by bkiskac           #+#    #+#             */
/*   Updated: 2025/02/11 20:54:13 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	ft_atol(char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}

static long	check_range(t_data *data, char *str)
{
	long	num;

	num = ft_atol(str);
	if (num < 1 || num > INT_MAX)
		return (ERROR);
	return (num);
}

int	parse_input(int argc, char *argv[], t_data *data)
{
	data->philo_count = check_range(data, argv[1]);
	if (data->philo_count < 1)
		return (ERROR);
	data->time_to_die = check_range(data, argv[2]) * 1000;
	data->time_to_eat = check_range(data, argv[3]) * 1000;
	data->time_to_sleep = check_range(data, argv[4]) * 1000;
	if (data->time_to_die < 60000 || data->time_to_eat < 60000 || data->time_to_sleep < 60000)
		return (ERROR);
	if (argc == 6)
	{
		data->max_meals = check_range(data, argv[5]);
		if (data->max_meals < 1)
			return (ERROR);
	}
	else
		data->max_meals = -1;
	return (0);
}
