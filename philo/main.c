/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:49:36 by bkiskac           #+#    #+#             */
/*   Updated: 2025/03/08 12:00:59 by bkiskac          ###   ########.fr       */
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
	if (parse_input(argc, argv, prog) == ERROR)
		return (free(prog), ERROR);
	if (data_init(prog) == ERROR)
		return (clean_up(prog), ERROR);
	if (start_threads(prog) == ERROR)
		return (clean_up(prog), ERROR);
	monitor(prog);
	if (join_threads(prog) == ERROR)
		return (clean_up(prog), ERROR);
	clean_up(prog);
	return (0);
}
