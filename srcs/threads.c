/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:07:11 by brunogue          #+#    #+#             */
/*   Updated: 2025/05/19 18:39:55 by brunogue         ###   ########.fr       */
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

static bool	all_ate(t_data *data)
{
	int	i;
	int	eaten;

	i = 0;
	if (data->must_eat_count <= 0)
		return (false);
	while (i < data->nb_philos)
	{
		pthread_mutex_lock(&data->meals_mutex);
		eaten = data->philos[i].meals_eaten;
		pthread_mutex_unlock(&data->meals_mutex);
		if (eaten < data->must_eat_count)
			return (false);
		i++;
	}
	return (true);
}

int	is_alive(t_data *data, int status)
{
	int	old;

	pthread_mutex_lock(&data->lock);
	old = data->someone_died;
	if (status != 0)
		data->someone_died = 1;
	pthread_mutex_unlock(&data->lock);
	return old;

}

void *routine(void *arg)
{
    t_thread *ph = arg;
    t_data   *d  = ph->data;

    while (!is_alive(d, 0))
    {
        if (check_death(ph))
            break;
        print_status(ph, "is thinking");
        pickup_forks(ph);
        eat(ph);
        put_down_forks(ph);
        if (all_ate(d))
        {
            is_alive(d, 1);
            break;
        }
        print_status(ph, "is sleeping");
        smart_sleep(d->time_to_sleep, d);

        if (check_death(ph))
            break;
    }
    return (NULL);
}
