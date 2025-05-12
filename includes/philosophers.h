/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:34:08 by brunogue          #+#    #+#             */
/*   Updated: 2025/05/12 13:55:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>

typedef struct s_data t_data;

typedef struct s_thread
{
	int				id;
	int				meals_eaten;
	long long		last_meal;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_data			*data;
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
	t_thread		*philos;
}	t_data;



//INIT.C
bool	init_structs(int ac, char **av, t_data *data);
bool	init_data(t_data *data);
bool	check_args(int ac, char **av);
bool check_death(t_thread *ph);
void	*routine(void *arg);

//ACTIONS.C
//PRINT.C
//SIMULATION.C
//CLEANUP.C
void cleanup(t_data *data);

//THREADS.G
bool	start_threads(t_data *data);
void	join_threads(t_data *data);
void	print_status(t_thread *ph, const char *msg);
void	pickup_forks(t_thread *ph);
void	eat(t_thread *ph);

//THREADS2.C
void	put_down_forks(t_thread *ph);

//UTILS.C
int			ft_atoi(char *n);
long long get_time(void);
void	smart_sleep(long long duration, t_data *data);

#endif