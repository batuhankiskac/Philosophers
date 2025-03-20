/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:27:42 by bkiskac           #+#    #+#             */
/*   Updated: 2025/03/18 13:25:08 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_valid_number(char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

static long	ft_atol(char *str)
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

static long	check_range(char *str)
{
	long	num;

	if (!is_valid_number(str))
	{
		printf("Invalid Input!\n");
		return (ERROR);
	}
	num = ft_atol(str);
	if (num < 1 || num > 2147483647)
		return (ERROR);
	return (num);
}

int	parse_input(int argc, char *argv[], t_program *prog)
{
	prog->philo_num = (int)check_range(argv[1]);
	if (prog->philo_num < 1)
		return (ERROR);
	prog->time_to_die = (size_t)check_range(argv[2]);
	if (prog->time_to_die == (size_t)ERROR)
		return (ERROR);
	prog->time_to_eat = (size_t)check_range(argv[3]);
	if (prog->time_to_eat == (size_t)ERROR)
		return (ERROR);
	prog->time_to_sleep = (size_t)check_range(argv[4]);
	if (prog->time_to_sleep == (size_t)ERROR)
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
