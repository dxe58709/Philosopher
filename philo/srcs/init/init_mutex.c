/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:03:32 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/14 21:42:12 by nsakanou         ###   ########.fr       */
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
			destroy_mutex(data->forks_mtx, i);
			return (false);
		}
		i++;
	}
	if (pthread_mutex_init(&data->print_mtx, NULL) != 0)
	{
		destroy_mutex(data->forks_mtx, data->args.number_of_philo);
		return (false);
	}
	if (pthread_mutex_init(&data->exit_flag_mtx, NULL) != 0)
	{
		destroy_mutex(data->forks_mtx, data->args.number_of_philo);
		pthread_mutex_destroy(&data->print_mtx);
		return (false);
	}
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
