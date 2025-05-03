/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:25:28 by brunogue          #+#    #+#             */
/*   Updated: 2025/05/03 19:30:53 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	while (n == ' ' || n == '\t' || n == '\n'
		|| n == '\v' || n == '\f' || n == '\r')
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
}