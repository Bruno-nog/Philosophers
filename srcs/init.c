/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:44:30 by brunogue          #+#    #+#             */
/*   Updated: 2025/05/10 18:06:01 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	init_structs(int ac, char **av, t_data *data)
{
	(void)ac;
	data->nb_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->must_eat_count = ft_atoi(av[5]);
	if (data->nb_philos <= 0 || data->time_to_die <= 0 || data->time_to_die <= 0 || data->time_to_eat <= 0)
	{
		printf("Error: arguments must be more than 0\n");
		return (1);
	}
	data->someone_died = false;
	data->start_time = get_time();
	return (true);
}

bool	check_args(int ac, char **av)
{
	(void)av;
	int	i;

	i = 0;
	if (ac != 5 && ac != 6)
	{
		printf("Error, expected 5 or 6 arguments.\n");
		return (1);
	}
	return (0);
}

static void	fill_thread(t_data *data)
{
	t_thread	*ph;
	int			i;

	i = 0;
	while (i < data->nb_philos)
	{
		ph = &data->philos[i];
		ph->id = i + 1;
		ph->meals_eaten = 0;
		ph->last_meal = data->start_time;
		ph->data = data;
		ph->l_fork = &data->forks[i];
		ph->r_fork = &data->forks[(i + 1) % data->nb_philos];
		i++;
	}
}

bool	init_data(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->forks)
		return (false);
	while (i < data->nb_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (false);
	data->philos = malloc(sizeof(t_thread) * data->nb_philos);
	if (!data->philos)
		return (false);
	fill_thread(data);
	return (true);
}

void	*routine(void *arg)
{
	t_thread	*ph;

	ph = arg;
	while (!ph->data->someone_died)
	{
		print_status(ph, "is thinking");
		pickup_forks(ph);
		eat(ph);
		put_down_forks(ph);
		print_status(ph);
		print_status(ph, "is sleeping");
		smart_sleep(ph->data->time_to_sleep, ph->data);
	}
	return (NULL);
}