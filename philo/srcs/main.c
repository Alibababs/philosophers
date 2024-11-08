/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbailly <pbailly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:41:58 by pbailly           #+#    #+#             */
/*   Updated: 2024/10/20 14:16:06 by pbailly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if ((argc != 5 && argc != 6) || invalid_input(argv))
		return (write_error("Invalid arguments\n"));
	if (init(argv, &data))
		return (1);
	if (dining(&data))
		return (1);
	return (0);
}
