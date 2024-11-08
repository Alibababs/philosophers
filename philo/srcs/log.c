/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbailly <pbailly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:43:27 by pbailly           #+#    #+#             */
/*   Updated: 2024/10/22 00:13:56 by pbailly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_log(t_data *data, t_philo *philo, char c)
{
	long	time;

	pthread_mutex_lock(&data->write);
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
			/* if (c == 'D')
				printf(RED "%ld %d died 💀\n" RESET, time, philo->id); */
			if (c == 'D')
				printf("%ld %d died\n", time, philo->id);
			if (c == 'X')
				printf(GREEN "%ld Everyone finished their spaghetti ! 🎉\n" RESET,
					time + data->t_eat);
		}
	}
	pthread_mutex_unlock(&data->write);
}

// 5 610 200 100 10
// 5 601 200 200 10

//	50 401 200 200 10
// 1       Pass    [✓]
// 2       Fail    [x]     3401 1 died

//	130 401 200 200 10
// 1       Fail    [x]     1602 1 died
// 2       Pass    [✓]
// 3       Pass    [✓]
// 4       Fail    [x]     2202 1 died

// 198 401 200 200 10

/* 	31 599 200 200 10
1       Pass    [✓]     1200 1 died
2       Pass    [✓]     799 1 died
3       Pass    [✓]     799 1 died
4       Pass    [✓]     999 1 died
5       Fail    [x] */

//	131 600 200 200 10
