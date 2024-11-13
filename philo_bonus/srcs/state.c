/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibaba <alibaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:42:49 by pbailly           #+#    #+#             */
/*   Updated: 2024/11/13 16:16:29 by alibaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_finished(t_data *data)
{
	int	value;

	sem_wait(data->monitor);
	value = data->is_finished;
	sem_post(data->monitor);
	return (value);
}

int	ft_is_dead(t_data *data)
{
	int	value;

	sem_wait(data->dead);
	value = data->is_dead;
	sem_post(data->dead);
	return (value);
}

void	set_death(t_data *data, t_philo *philo)
{
	ft_log(data, philo, 'D');
	sem_wait(data->dead);
	data->is_dead = 1;
	sem_post(data->dead);
}

int	meal_counter(t_data *data, t_philo *philo)
{
	int	value;

	sem_wait(data->meal);
	value = philo->meals_eaten;
	sem_post(data->meal);
	return (value);
}

void	set_end(t_data *data, t_philo *philo)
{
	ft_log(data, philo, 'X');
	sem_wait(data->monitor);
	data->is_finished = 1;
	sem_post(data->monitor);
}
