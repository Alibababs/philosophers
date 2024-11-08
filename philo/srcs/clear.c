/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbailly <pbailly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:13:10 by pbailly           #+#    #+#             */
/*   Updated: 2024/10/20 19:15:14 by pbailly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_clear_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
	{
		if (pthread_mutex_destroy(&data->forks[i]) != 0)
			return (write_error("pthread destroy error"));
	}
	if (pthread_mutex_destroy(&data->write) != 0)
		return (write_error("pthread destroy error"));
	if (pthread_mutex_destroy(&data->meal) != 0)
		return (write_error("pthread destroy error"));
	if (pthread_mutex_destroy(&data->dead) != 0)
		return (write_error("pthread destroy error"));
	if (pthread_mutex_destroy(&data->monitor) != 0)
		return (write_error("pthread destroy error"));
	free(data->philo);
	free(data->forks);
	return (0);
}
