/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:34:08 by brunogue          #+#    #+#             */
/*   Updated: 2025/05/20 13:54:47 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct s_data	t_data;

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
	pthread_mutex_t	lock;
	pthread_mutex_t	meals_mutex;
	t_thread		*philos;
}	t_data;

//THREADS.G
bool		start_threads(t_data *data);
int			is_alive(t_data *data, int status);
void		*routine(void *arg);

//THREADS2.C
void		put_down_forks(t_thread *ph);
void		join_threads(t_data *data);
void		print_status(t_thread *ph, const char *msg);
void		pickup_forks(t_thread *ph);
void		eat(t_thread *ph);

//INIT.C
bool		init_structs(int ac, char **av, t_data *data);
bool		init_data(t_data *data);

//UTILS.C
long long	get_time(void);
void		smart_sleep(long long duration, t_data *data);
bool		check_death(t_thread *ph);
bool		check_args(int ac, char **av);

//UTILS2.C
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_atoi(char *n);
bool		ft_is_digit(char s);
int			ft_strcmp(const char *s1, const char *s2);

//CLEANUP.C
void		cleanup(t_data *data);

#endif