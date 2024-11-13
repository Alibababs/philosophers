/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibaba <alibaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:41:04 by pbailly           #+#    #+#             */
/*   Updated: 2024/11/13 16:03:34 by alibaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define BLUE "\033[0;34m"
# define PURPLE "\033[35m"
# define RED "\033[0;31m"
# define ORANGE "\033[38;5;214m"
# define GREEN "\033[0;32m"
# define RESET "\033[0m"

typedef struct s_philo	t_philo;

typedef struct s_data
{
	long				n_philo;
	long				t_die;
	long				t_eat;
	long				t_sleep;
	long				n_meal;
	long				start;
	int					is_dead;
	int					is_finished;
	sem_t				*forks;
	sem_t				*write;
	sem_t				*meal;
	sem_t				*dead;
	sem_t				*monitor;
	t_philo				*philo;
}						t_data;

struct					s_philo
{
	int					id;
	int					meals_eaten;
	long				t_last_meal;
	pthread_t			thread;
	t_data				*data;
};

// STATE

int						ft_is_finished(t_data *data);
int						ft_is_dead(t_data *data);
int						meal_counter(t_data *data, t_philo *ph);
void					set_death(t_data *data, t_philo *ph);
void					set_end(t_data *data, t_philo *philo);

// LOG

void					ft_log(t_data *data, t_philo *philo, char c);

// DINING

int						dining(t_data *data);

// INIT

int						init(char **argv, t_data *data);

// ERROR

int						write_error(char *str);
int						invalid_input(char **argv);

// FREE

int						ft_clear_mutex(t_data *data);

// UTILS

long					ft_atol(const char *str);
long					get_time(void);
void					ft_usleep(long time, t_data *data);

#endif