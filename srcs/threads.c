/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:07:11 by brunogue          #+#    #+#             */
/*   Updated: 2025/05/12 17:34:42 by brunogue         ###   ########.fr       */
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

	i = 0;
	if (data->must_eat_count <= 0)
		return (false);
	while (i < data->nb_philos)
	{
		if (data->philos[i].meals_eaten < data->must_eat_count)
			return (false);
		i++;
	}
	return (true);
}

void *routine(void *arg)
{
    t_thread *ph;

	ph = arg;
    while (!ph->data->someone_died)
    {
        if (check_death(ph))
            break ;
        print_status(ph, "is thinking");
        pickup_forks(ph);
        eat(ph);
        put_down_forks(ph);
		if (all_ate(ph->data))
		{
			ph->data->someone_died = true;
			break ;
		}
        print_status(ph, "is sleeping");
        smart_sleep(ph->data->time_to_sleep, ph->data);
        if (check_death(ph))
            break;
    }
    return (NULL);
}
