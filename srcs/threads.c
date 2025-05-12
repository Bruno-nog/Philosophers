/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:07:11 by brunogue          #+#    #+#             */
/*   Updated: 2025/05/12 12:50:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	start_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &routine, &data->philos[i]) != 0)
		{
			printf("Error creating thread %d\n", i + 1);
			return (false);
		}
		i++;
	}
	return (true);
}

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

void	print_status(t_thread *ph, const char *msg)
{
	long long	ts;

	pthread_mutex_lock(&ph->data->print_mutex);
	ts = get_time() - ph->data->start_time;
	printf("%lld %d %s\n", ts, ph->id, msg);
	pthread_mutex_unlock(&ph->data->print_mutex);
}

void pickup_forks(t_thread *ph)
{
    if (ph->id % 2)
    {
        pthread_mutex_lock(ph->l_fork);
        print_status(ph, "has taken a fork");
        pthread_mutex_lock(ph->r_fork);
        print_status(ph, "has taken a fork");
    }
    else
    {
        pthread_mutex_lock(ph->r_fork);
        print_status(ph, "has taken a fork");
        pthread_mutex_lock(ph->l_fork);
        print_status(ph, "has taken a fork");
    }
}

void eat(t_thread *ph)
{
    t_data *d = ph->data;

    pthread_mutex_lock(&d->print_mutex);
    ph->last_meal = get_time();
    pthread_mutex_unlock(&d->print_mutex);

    print_status(ph, "is eating");
    ph->meals_eaten++;
    smart_sleep(d->time_to_eat, d);
}