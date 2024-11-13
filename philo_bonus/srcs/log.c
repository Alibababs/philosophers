/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibaba <alibaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:43:27 by pbailly           #+#    #+#             */
/*   Updated: 2024/11/13 17:16:43 by alibaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_log(t_data *data, t_philo *philo, char c)
{
	long	time;

	sem_wait(data->write);
	time = get_time() - data->start;
	if (!ft_is_finished(data))
	{
		if (!ft_is_dead(data))
		{
			if (c == 'F')
				printf("%ld %d has taken a fork 🥄\n", time, philo->id);
			if (c == 'E')
				printf(ORANGE "%ld %d is eating 🍝\n" RESET, time, philo->id);
			if (c == 'S')
				printf(BLUE "%ld %d is sleeping 💤\n" RESET, time, philo->id);
			if (c == 'T')
				printf(PURPLE "%ld %d is thinking 🗿\n" RESET, time, philo->id);
			if (c == 'D')
				printf(RED "%ld %d died 💀\n" RESET, time, philo->id);
			if (c == 'X')
				printf(GREEN "%ld Everyone finished their spaghetti !🎉\n" RESET,
					time + data->t_eat);
		}
	}
	sem_post(data->write);
}
