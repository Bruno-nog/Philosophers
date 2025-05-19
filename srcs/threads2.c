/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:58:26 by marvin            #+#    #+#             */
/*   Updated: 2025/05/12 10:58:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	put_down_forks(t_thread *ph)
{
	pthread_mutex_unlock(ph->l_fork);
	pthread_mutex_unlock(ph->r_fork);
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
    pthread_mutex_lock(&d->meals_mutex);
    ph->meals_eaten++;
    pthread_mutex_unlock(&d->meals_mutex);
    smart_sleep(d->time_to_eat, d);
}
