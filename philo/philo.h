/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:57:46 by bkiskac           #+#    #+#             */
/*   Updated: 2025/02/11 22:01:53 by bkiskac          ###   ########.fr       */
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

typedef struct s_philo
{
	int				id;
	long			last_meal;
	int				meals_eaten;
	int				left_fork_id;
	int				right_fork_id;
	pthread_t		thread;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	long			philo_count;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			max_meals;
	bool			end_sim;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	*forks;
	pthread_mutex_t	meal_lock;
	struct timeval	start_time;
	struct s_philo	*philos;
}				t_data;

int	parse_input(int argc, char *argv[], t_data *data);

#endif
