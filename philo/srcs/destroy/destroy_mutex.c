/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:04:12 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/14 20:43:04 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(pthread_mutex_t *mutex, unsigned int count)
{
	unsigned int	i;

	i = 0;
	while (i < count)
	{
		if (pthread_mutex_destroy(&mutex[i]) != 0)
			print_error("Failed to destroy mutex\n");
		i++;
	}
}
