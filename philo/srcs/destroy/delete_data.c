/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:33:47 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/14 21:09:32 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	delete_mutexes(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->args.number_of_philo)
	{
		pthread_mutex_destroy(&data->forks_mtx[i]);
		pthread_mutex_destroy(&data->philo[i].count_eaten_mtx);
		pthread_mutex_destroy(&data->philo[i].last_meal_time_mtx);
		i++;
	}
	pthread_mutex_destroy(&data->exit_flag_mtx);
	pthread_mutex_destroy(&data->print_mtx);
}

void	delete_data(t_data *data)
{
	delete_mutexes(data);
	free(data->threads);
	free(data->forks_mtx);
	free(data->philo);
}
