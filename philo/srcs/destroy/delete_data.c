/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:33:47 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/13 21:44:32 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	delete_data(t_data *data)
{
	unsigned int	i;

	i = 0;
	if (data->philo)
	{
		while (i < data->args.number_of_philo)
		{
			destroy_mutex(&data->philo[i].count_eaten_mtx, 1);
			destroy_mutex(&data->philo[i].last_meal_time_mtx, 1);
			i++;
		}
		free(data->philo);
	}
	if (data->threads)
		free(data->threads);
	if (data->forks_mtx)
	{
		destroy_mutex(data->forks_mtx, data->args.number_of_philo);
		free(data->forks_mtx);
	}
	pthread_mutex_destroy(&data->exit_flag_mtx);
	pthread_mutex_destroy(&data->print_mtx);
}
