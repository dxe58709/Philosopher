/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:33:47 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/12 18:39:59 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	delete_data(t_data *data)
{
	unsigned int	i;

	i = 0;
	// while (i < data->args.number_of_philo)
	// {
	// 	pthread_mutex_destroy(&data->philo[i].count_eaten_mtx);
	// 	pthread_mutex_destroy(&data->philo[i].last_meal_time_mtx);
	// 	pthread_mutex_destroy(&data->forks_mtx[i]);
	// 	i++;
	// }
	destroy_mutex(&data->philo[i].count_eaten_mtx, data->args.number_of_philo);
	destroy_mutex(&data->philo[i].last_meal_time_mtx,
		data->args.number_of_philo);
	destroy_mutex(&data->forks_mtx[i], data->args.number_of_philo);
	pthread_mutex_destroy(&data->stop_mtx);
	pthread_mutex_destroy(&data->print_mtx);
	free(data->philo);
	free(data->threads);
	free(data->forks_mtx);
}

void cleanup_data(t_data *data)
{
    if (data->philo)
        free(data->philo);
    if (data->threads)
        free(data->threads);
    if (data->forks_mtx)
    {
        for (unsigned int i = 0; i < data->args.number_of_philo; ++i)
            pthread_mutex_destroy(&data->forks_mtx[i]);
        free(data->forks_mtx);
    }
    pthread_mutex_destroy(&data->stop_mtx);
    pthread_mutex_destroy(&data->print_mtx);
}
