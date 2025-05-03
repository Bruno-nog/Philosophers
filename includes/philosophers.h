/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:34:08 by brunogue          #+#    #+#             */
/*   Updated: 2025/05/03 17:42:46 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <> 

typedef struct s_thread
{
	int				id;
	int				meals_eaten;
	long long		last_meal;
	pthread_t		thread;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	r_fork;
	struct d_data	*data;
}	t_thread;

typedef struct s_data
{
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	int				someone_died;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	t_thread		*philos
}	t_data;

#endif



t_data *data;

data->nb_philos = ft_atoi(argv[1])
data->time_to_die = ft_atoi(argv[2])
data->nb_philos = ft_atoi(argv[3])
data->nb_philos = ft_atoi(argv[4])

if (argv[5])
	data->times_must_eat = ft_atoi(argv[5])
	