/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbailly <pbailly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:30:06 by pbailly           #+#    #+#             */
/*   Updated: 2024/10/31 17:36:56 by pbailly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_one_philo(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->forks[philo->r_fork]);
	ft_log(data, philo, 'F');
	pthread_mutex_unlock(&data->forks[philo->r_fork]);
	ft_usleep(data->t_die, data);
	ft_log(data, philo, 'D');
}

static void	ft_is_eating(t_data *data, t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(&data->forks[philo->l_fork]);
		ft_log(data, philo, 'F');
		pthread_mutex_lock(&data->forks[philo->r_fork]);
		ft_log(data, philo, 'F');
	}
	else
	{
		pthread_mutex_lock(&data->forks[philo->r_fork]);
		ft_log(data, philo, 'F');
		pthread_mutex_lock(&data->forks[philo->l_fork]);
		ft_log(data, philo, 'F');
	}
	pthread_mutex_lock(&data->meal);
	philo->t_last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&data->meal);
	ft_log(data, philo, 'E');
	ft_usleep(data->t_eat, data);
	pthread_mutex_unlock(&data->forks[philo->l_fork]);
	pthread_mutex_unlock(&data->forks[philo->r_fork]);
}

static void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (data->n_philo == 1)
		return (ft_one_philo(data, philo), NULL);
	if (philo->id % 2 == 0)
		ft_usleep(15, data);
	while (!ft_is_dead(data))
	{
		ft_is_eating(data, philo);
		if (ft_is_finished(data))
			break ;
		ft_log(data, philo, 'S');
		ft_usleep(data->t_sleep, data);
		ft_log(data, philo, 'T');
		usleep(100);
	}
	return (NULL);
}

static void	observer(t_data *data, t_philo *philo)
{
	int	i;

	while (!ft_is_finished(data))
	{
		i = -1;
		while (++i < data->n_philo && !ft_is_dead(data))
		{
			pthread_mutex_lock(&data->meal);
			if ((get_time() - philo[i].t_last_meal) >= data->t_die)
			{
				set_death(data, philo);
				pthread_mutex_unlock(&data->meal);
				return ;
			}
			pthread_mutex_unlock(&data->meal);
		}
		i = 0;
		while (i < data->n_philo && data->n_meal != -1 && meal_counter(data,
				&philo[i]) >= data->n_meal)
			i++;
		if (i == data->n_philo)
			set_end(data, philo);
		usleep(10);
	}
}

int	dining(t_data *data)
{
	t_philo	*philo;
	int		i;

	philo = data->philo;
	i = -1;
	data->start = get_time();
	while (++i < data->n_philo)
	{
		data->philo[i].t_last_meal = get_time();
		if (pthread_create(&(philo[i].thread), NULL, &routine, &philo[i]) != 0)
			return (write_error("pthread create error\n"));
	}
	if (data->n_philo > 1)
		observer(data, philo);
	i = -1;
	while (++i < data->n_philo)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (write_error("pthread join error\n"));
	}
	if (ft_clear_mutex(data))
		return (1);
	return (0);
}
