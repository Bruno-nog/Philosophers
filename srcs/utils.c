/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:25:28 by brunogue          #+#    #+#             */
/*   Updated: 2025/05/10 12:51:45 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	while (!data->someone_died)
	{
		if (get_time() - start >= duration)
			break ;
		usleep(100);
	}
}