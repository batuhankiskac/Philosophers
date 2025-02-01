/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:49:36 by bkiskac           #+#    #+#             */
/*   Updated: 2025/02/01 12:58:26 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char  *argv[])
{
	t_data *data;

	if (argc == 5 || argc == 6)
	{
		if (parse_input(&data, argv) == ERROR)
			return (ERROR);
		if (data_init(&data) == ERROR)
			return (ERROR);
		if (dinner_start(&data, argv) == ERROR)
			return (ERROR);
		if (cleanup_data(&data) == ERROR)
			return (ERROR);
		return (0);
	}
	return (ERROR);
}

