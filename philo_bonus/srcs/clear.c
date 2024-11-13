/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibaba <alibaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:13:10 by pbailly           #+#    #+#             */
/*   Updated: 2024/11/13 16:13:38 by alibaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_clear_mutex(t_data *data)
{
	sem_close(data->forks);
	sem_close(data->write);
	sem_close(data->meal);
	sem_close(data->dead);
	sem_close(data->monitor);
	free(data->philo);
	return (0);
}
