/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:33:42 by brunogue          #+#    #+#             */
/*   Updated: 2025/05/07 19:33:21 by brunogue         ###   ########.fr       */
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

int main (int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof (t_data));
	if (!check_args(ac, av))
		return (1);
	if (!init_structs(ac, av, data))
		return (1);
	return (0);
}
