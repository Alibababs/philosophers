/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibaba <alibaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:46:29 by pbailly           #+#    #+#             */
/*   Updated: 2024/11/13 16:22:25 by alibaba          ###   ########.fr       */
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
	}
	return (0);
}

static int	init_sem(t_data *data)
{
	sem_unlink("forks");
	sem_unlink("write");
	sem_unlink("meal");
	sem_unlink("dead");
	sem_unlink("monitor");
	data->forks = sem_open("forks", O_CREAT, 0600, data->n_philo);
	data->write = sem_open("write", O_CREAT, 0600, 1);
	data->meal = sem_open("meal", O_CREAT, 0600, 1);
	data->dead = sem_open("dead", O_CREAT, 0600, 1);
	data->monitor = sem_open("monitor", O_CREAT, 0600, 1);
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
	if (init_sem(data))
		return (1);
	if (init_philo(data))
		return (1);
	return (0);
}
