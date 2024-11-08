/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbailly <pbailly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:42:49 by pbailly           #+#    #+#             */
/*   Updated: 2024/10/20 18:26:51 by pbailly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_finished(t_data *data)
{
	int	value;

	pthread_mutex_lock(&data->monitor);
	value = data->is_finished;
	pthread_mutex_unlock(&data->monitor);
	return (value);
}

int	ft_is_dead(t_data *data)
{
	int	value;

	pthread_mutex_lock(&data->dead);
	value = data->is_dead;
	pthread_mutex_unlock(&data->dead);
	return (value);
}

void	set_death(t_data *data, t_philo *philo)
{
	ft_log(data, philo, 'D');
	pthread_mutex_lock(&data->dead);
	data->is_dead = 1;
	pthread_mutex_unlock(&data->dead);
}

int	meal_counter(t_data *data, t_philo *philo)
{
	int	value;

	pthread_mutex_lock(&data->meal);
	value = philo->meals_eaten;
	pthread_mutex_unlock(&data->meal);
	return (value);
}

void	set_end(t_data *data, t_philo *philo)
{
	ft_log(data, philo, 'X');
	pthread_mutex_lock(&data->monitor);
	data->is_finished = 1;
	pthread_mutex_unlock(&data->monitor);
}
