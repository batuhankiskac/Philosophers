/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:17:42 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/30 18:29:58 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

inline bool	is_space(char *str)
{
	return (*str == ' ' || (*str >= 9 && *str <= 12));
}

inline bool	is_digit(char *str)
{
	return (*str >= '0' && *str <= '9');
}

void	*error_return(char *msg)
{
	printf("%s", msg);
	return (NULL);
}
