/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:57:46 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/30 18:23:58 by bkiskac          ###   ########.fr       */
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

# define ERR_ARGS "Wrong Argument! Usage: ./philo <number> <die_time> <eat_time> <sleep_time> [max_meals]\n"
# define ERR_MUTEX "Mutex could not initialized\n"
# define ERR_THREAD "Thread could not create\n"

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
	bool			end_sim;
	struct s_philo	*philos;
}					t_data;


typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	long			meals_eaten;
	long			last_meal;
	bool			is_full;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}					t_philo;

inline bool	is_space(char *str);
inline bool	is_digit(char *str);

#endif
