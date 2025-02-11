/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:01:36 by bkiskac           #+#    #+#             */
/*   Updated: 2025/02/11 14:21:48 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_valid(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

static long	ft_atol(char *str)
{
	long	res;
	int		i;

	res = 0;
	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

int	parse_input(t_data *data, char *argv[])
{
	if (!is_valid(argv[1]) || !is_valid(argv[2])
		|| !is_valid(argv[3]) || !is_valid(argv[4])
		|| (argv[5] && !is_valid(argv[5])))
		return (ERROR);
	data->philo_count = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	if (!argv[5])
		data->max_meal = -1;
	else
		data->max_meal = ft_atol(argv[5]);
	if (data->philo_count < 1 || data->time_to_die <= 0
		|| data->time_to_eat <= 0 || data->time_to_sleep <= 0
		|| (argv[5] && data->max_meal <= 0))
		return (ERROR);
	return (0);
}
