/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:25:28 by brunogue          #+#    #+#             */
/*   Updated: 2025/05/20 16:49:36 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_time(void)
{
	struct timeval	tv;
	long long		ms;

	gettimeofday(&tv, NULL);
	ms = (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000);
	return (ms);
}

void	smart_sleep(long long duration, t_data *data)
{
	long long	start;

	start = get_time();
	while (!is_alive(data, 0))
	{
		if (get_time() - start >= duration)
			break ;
		usleep(100);
	}
}

bool	check_death(t_thread *ph)
{
	if (get_time() - ph->last_meal > ph->data->time_to_die)
	{
		if (!is_alive(ph->data, 0))
		{
			print_status(ph, "died");
			is_alive(ph->data, 1);
		}
		return (true);
	}
	return (false);
}

bool	check_args(int ac, char **av)
{
	int	i;
	int	k;

	i = 0;
	k = 1;
	if (ac < 5 || ac > 6)
	{
		printf("Error, expected 5 or 6 arguments.\n");
		return (false);
	}
	while (av[k] != NULL)
	{
		i = 0;
		while (av[k][i])
		{
			if (ft_is_digit(av[k][i]))
				return (false);
			i++;
		}
		k++;
	}
	return (true);
}
