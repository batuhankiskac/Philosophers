/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:57:46 by bkiskac           #+#    #+#             */
/*   Updated: 2025/03/01 12:49:20 by bkiskac          ###   ########.fr       */
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
	pthread_t			thread;
	int					id;
	int					eating;
	int					meals_eaten;
	int					is_even;
	size_t				last_meal;
	size_t				start_time;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*write_lock;
	pthread_mutex_t		*dead_lock;
	pthread_mutex_t		*meal_lock;
	struct s_program	*prog;
}						t_philo;

typedef struct s_program
{
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				philo_num;
	int				max_meals;
	int				end_sim;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	struct s_philo	*philos;
}					t_program;

int		parse_input(int argc, char *argv[], t_program *prog);
int		data_init(t_program *prog);
int		start_threads(t_program *prog);
int		join_threads(t_program *prog);
int		ft_usleep(size_t milliseconds, int *dead);
int		monitor(t_program *prog);
int		clean_up(t_program *prog);
int		take_forks(t_philo *philo);
int		eat(t_philo *philo);
int		sleep_and_think(t_philo *philo);
size_t	get_current_time(void);
void	print_status(t_philo *philo, char *status);
void	single_philo_routine(t_philo *philo);
void	release_forks(t_philo *philo);

#endif
