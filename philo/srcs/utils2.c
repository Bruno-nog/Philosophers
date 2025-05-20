/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:27:51 by brunogue          #+#    #+#             */
/*   Updated: 2025/05/20 13:54:34 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > 4294967296 / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	memset(ptr, 0, nmemb * size);
	return (ptr);
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
	int	sign;

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

bool	ft_is_digit(char s)
{
	if (s >= '0' && s <= '9')
		return (false);
	return (true);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((unsigned char)s1[i] && (unsigned char)s2[i]
		&& s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
