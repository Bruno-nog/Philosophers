/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:33:42 by brunogue          #+#    #+#             */
/*   Updated: 2025/05/11 17:21:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



int main (int ac, char **av)
{
	t_data	*data;

	if (!check_args(ac, av))
		return (1);
	data = malloc(sizeof (t_data));
	if (!data)
		return (1);
	if (!init_structs(ac, av, data))
		return (1);
	if (!init_data(data))
		return (1);
	if (!start_threads(data))
		return (1);
	join_threads(data);
	return (0);
}
