/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:27:42 by bkiskac           #+#    #+#             */
/*   Updated: 2025/03/16 10:13:08 by bkiskac          ###   ########.fr       */
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
	if (num < 1 || num > 2147483647)
		return (ERROR);
	return (num);
}

int	parse_input(int argc, char *argv[], t_program *prog)
{
	prog->philo_num = (int)check_range(argv[1]);
	prog->time_to_die = (size_t)check_range(argv[2]);
	prog->time_to_eat = (size_t)check_range(argv[3]);
	prog->time_to_sleep = (size_t)check_range(argv[4]);
	if (prog->philo_num > 200 || prog->philo_num < 1
		|| prog->time_to_die < 60 || prog->time_to_eat < 60
		|| prog->time_to_sleep < 60)
		return (ERROR);
	if (argc == 6)
	{
		prog->max_meals = (int)check_range(argv[5]);
		if (prog->max_meals == ERROR)
			return (ERROR);
	}
	else
		prog->max_meals = -1;
	return (0);
}
