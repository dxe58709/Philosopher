/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:03:32 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/13 18:22:03 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_mutex(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->args.number_of_philo)
	{
		if (pthread_mutex_init(&data->forks_mtx[i], NULL) != 0)
		{
			destroy_mutex(&data->forks_mtx[i], data->args.number_of_philo);
			return (false);
		}
		i++;
	}
	if (pthread_mutex_init(&data->print_mtx, NULL))
		return (false);
	if (pthread_mutex_init(&data->exit_flag_mtx, NULL))
		return (false);
	return (true);
}

bool	can_init_mutex(t_data *data)
{
	if (!init_mutex(data))
	{
		print_error("Failed to initialize mutex.\n");
		return (false);
	}
	return (true);
}
