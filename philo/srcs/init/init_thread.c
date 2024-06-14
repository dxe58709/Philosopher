/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:34:31 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/14 21:38:07 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_thread(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * data->args.number_of_philo);
	if (!data->philo)
		return (false);
	data->threads = malloc(sizeof(pthread_t) * (data->args.number_of_philo));
	if (!data->threads)
	{
		free(data->philo);
		return (false);
	}
	data->forks_mtx = malloc(sizeof(pthread_mutex_t)
			* data->args.number_of_philo);
	if (!data->forks_mtx)
	{
		free(data->philo);
		free(data->threads);
		return (false);
	}
	return (true);
}

bool	can_init_thread(t_data *data)
{
	if (!init_thread(data))
	{
		print_error("Failed to initialize threads.\n");
		return (false);
	}
	return (true);
}
