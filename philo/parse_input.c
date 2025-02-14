/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:27:42 by bkiskac           #+#    #+#             */
/*   Updated: 2025/02/14 17:43:33 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

static long	check_range(const char *str)
{
	long	num;

	num = ft_atol(str);
	if (num < 1 || num > INT_MAX)
		return (ERROR);
	return (num);
}

int	parse_input(int argc, char *argv[], t_program *prog)
{
	if (argc != 5 && argc != 6)
		return (ERROR);
	prog->philos->num_of_philos = (int)check_range(argv[1]);
	if (prog->philos->num_of_philos == ERROR)
		return (ERROR);
	prog->philos->time_to_die = (size_t)check_range(argv[2]) * 1000;
	if (prog->philos->time_to_die == ERROR)
		return (ERROR);
	prog->philos->time_to_eat = (size_t)check_range(argv[3]) * 1000;
	if (prog->philos->time_to_eat == ERROR)
		return (ERROR);
	prog->philos->time_to_sleep = (size_t)check_range(argv[4]) * 1000;
	if (prog->philos->time_to_sleep == ERROR)
		return (ERROR);
	if (argc == 6)
	{
		prog->philos->max_meals = (int)check_range(argv[5]);
		if (prog->philos->max_meals == ERROR)
			return (ERROR);
	}
	else
		prog->philos->max_meals = -1;
	return (0);
}

