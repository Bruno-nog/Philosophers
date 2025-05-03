/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:22:39 by brunogue          #+#    #+#             */
/*   Updated: 2025/05/03 19:24:28 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


bool	check_args(int ac, char **av)
{
	if (ac != 5 || ac != 6)
	{
		printf("Error, expected 5 or 6 arguments.\n");
		return (1);
	}
	
}