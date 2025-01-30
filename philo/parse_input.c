/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:00:51 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/30 18:36:40 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*valid_input(char *str)
{
	int		len = 0;
	char	*number;

	while (is_space(str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		return (error_return("Only positive integers!"));
	if (!is_digit(str))
		return (error_return("Invalid input!"));
	number = str;
	while (is_digit(str))
	{
		len++;
		str++;
	}
	if (len > 10)
		return (error_return("Int MAX is the limit!"));
	return (number);
}

static long	ft_atol(char *str)
{
	long	num = 0;
	char	*valid;

	valid = valid_input(str);
	if (!valid)
		return (-1);
	while (*valid && is_digit(valid))
	{
		num = (num * 10) + (*valid - '0');
		valid++;
	}
	return (num);
}
