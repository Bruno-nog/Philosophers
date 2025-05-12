/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:58:26 by marvin            #+#    #+#             */
/*   Updated: 2025/05/12 10:58:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	put_down_forks(t_thread *ph)
{
	pthread_mutex_unlock(ph->l_fork);
	pthread_mutex_unlock(ph->r_fork);
}