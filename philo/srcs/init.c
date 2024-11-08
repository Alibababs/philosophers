/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbailly <pbailly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:46:29 by pbailly           #+#    #+#             */
/*   Updated: 2024/10/21 21:24:52 by pbailly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_philo(t_data *data)
{
	int	i;

	data->philo = malloc(sizeof(t_philo) * data->n_philo);
	if (!data->philo)
		return (write_error("Malloc error\n"));
	i = -1;
	while (++i < data->n_philo)
	{
		data->philo[i].data = data;
		data->philo[i].id = i + 1;
		data->philo[i].meals_eaten = 0;
		data->philo[i].r_fork = i;
		data->philo[i].l_fork = (i + 1) % data->n_philo;
	}
	return (0);
}

static int	init_mutex(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->forks)
		return (write_error("malloc error\n"));
	i = -1;
	while (++i < data->n_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (write_error("pthread init error"));
	}
	if (pthread_mutex_init(&data->write, NULL) != 0)
		return (write_error("pthread init error"));
	if (pthread_mutex_init(&data->meal, NULL) != 0)
		return (write_error("pthread init error"));
	if (pthread_mutex_init(&data->dead, NULL) != 0)
		return (write_error("pthread init error"));
	if (pthread_mutex_init(&data->monitor, NULL) != 0)
		return (write_error("pthread init error"));
	return (0);
}

int	init(char **argv, t_data *data)
{
	data->n_philo = ft_atol(argv[1]);
	data->t_die = ft_atol(argv[2]);
	data->t_eat = ft_atol(argv[3]);
	data->t_sleep = ft_atol(argv[4]);
	data->n_meal = -1;
	if (argv[5])
		data->n_meal = ft_atol(argv[5]);
	data->is_dead = 0;
	data->is_finished = 0;
	if (init_mutex(data))
		return (1);
	if (init_philo(data))
		return (1);
	return (0);
}
