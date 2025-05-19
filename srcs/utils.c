/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:25:28 by brunogue          #+#    #+#             */
/*   Updated: 2025/05/19 17:48:29 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

bool	ft_is_digit(char s)
{
	if (s >= '0' && s <= '9')
		return (false);
	return (true);
}

long long get_time(void)
{
	struct timeval	tv;
	long long		ms;

	gettimeofday(&tv, NULL);
	ms = (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000);
	return (ms);
}

static int	ft_conditions(int result, int sign)
{
	if (result > (2147483647 - (result * 10)) / 10)
	{
		if (sign == 1)
			return (2147483647);
		else
			return (-2147483648);
	}
	return (0);
}
int	ft_atoi(char *n)
{
	int	res;
	int sign;

	res = 0;
	sign = 1;
	while (*n == ' ' || *n == '\t' || *n == '\n'
		|| *n == '\v' || *n == '\f' || *n == '\r')
		n++;
	if (*n == '-')
	{
		sign = -1;
		n++;
	}
	if (*n == '+' || *n == '-')
		n++;
	while (*n >= '0' && *n <= '9')
	{
		ft_conditions(res, sign);
		res = res * 10 + (*n - '0');
		n++;
	}
	return (res * sign);
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
