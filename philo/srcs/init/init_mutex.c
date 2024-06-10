/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:03:32 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/10 17:45:33 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_mutex(pthread_mutex_t *mutex, unsigned int count)
{
	unsigned int	i;

	i = 0;
	while (i < count)
	{
		if (pthread_mutex_init(&mutex[i], NULL) != 0)
		{
			destroy_mutex(mutex, count);
			return (false);
		}
		i++;
	}
	return (true);
}
