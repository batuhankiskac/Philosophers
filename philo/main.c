/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:49:36 by bkiskac           #+#    #+#             */
/*   Updated: 2025/02/14 20:27:01 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_program	*prog;

	if (argc != 5 && argc != 6)
		return (ERROR);
	prog = malloc(sizeof(t_program));
	if (!prog)
		return (ERROR);
	if (parse_input(argc, argv, prog->philos) == ERROR)
	{
		free(prog);
		return (ERROR);
	}
	if (data_init(prog) == ERROR)
	{
		clean_up(prog);
		return (ERROR);
	}
	if (dinner_start(prog) == ERROR)
	{
		clean_up(prog);
		return (ERROR);
	}
	if (clean_up(prog) == ERROR)
		return (ERROR);
	return (0);
}
