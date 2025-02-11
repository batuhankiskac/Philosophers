/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:57:46 by bkiskac           #+#    #+#             */
/*   Updated: 2025/02/11 17:28:05 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

# define ERROR -1

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}			t_opcode;

typedef struct s_data
{
	long			philo_count;
	long			max_meal;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	print_lock;
	struct s_philo	*philos;
	bool			end_sim;
}					t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	long			meals_eaten;
	long			last_meal;
	bool			is_full;
	bool			is_dead;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}					t_philo;

int	parse_input(t_data *data, char *argv[]);
int	mutex_handle(pthread_mutex_t *mutex, t_opcode opcode);
int	thread_handle(pthread_t thread, t_opcode opcode, void *(*func)(void *));
int	data_init(t_data *data);
int	get_time(void);

#endif
