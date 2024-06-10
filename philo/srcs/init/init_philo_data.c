/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:30:21 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/10 18:17:53 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_philo(t_data *data)
{
	unsigned int	i;

	i = 0;
	data->starting_time = 0;
	data->stop = false;
	while (i < data->args.number_of_philo)
	{
		data->philo[i].philo_id = i + 1;
		data->philo[i].count_eaten = 0;
		data->philo[i].last_meal_time = 0;
		data->philo[i].left_fork_mtx = &data->forks_mtx[i];
		data->philo[i].right_fork_mtx = &data->forks_mtx[(i + 1)
			% data->args.number_of_philo];
		pthread_mutex_init(&data->philo[i].count_eaten_mtx, NULL);
		pthread_mutex_init(&data->philo[i].last_meal_time_mtx, NULL);
		data->philo[i].data = data;
		i++;
	}
	return (true);
}

bool	check_init_philo_data(t_data *data)
{
	if (!init_philo(data))
	{
		print_error("Not init philo_data.\n");
		return (false);
	}
	return (true);
}
