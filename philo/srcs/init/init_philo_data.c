/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:30:21 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/14 00:53:07 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_philo_data(t_data *data)
{
	unsigned int	i;

	i = 0;
	data->starting_time = get_current_time();
	while (i < data->args.number_of_philo)
	{
		data->philo[i].philo_id = i + 1;
		data->philo[i].count_eaten = 0;
		data->philo[i].last_meal_time = 0;
		data->philo[i].left_fork_mtx = &data->forks_mtx[i];
		data->philo[i].right_fork_mtx = &data->forks_mtx[(i + 1)
			% data->args.number_of_philo];
		if (pthread_mutex_init(&data->philo[i].count_eaten_mtx, NULL)
			|| pthread_mutex_init(&data->philo[i].last_meal_time_mtx, NULL))
		{
			print_error("Failed to initialize mutex.\n");
			delete_data(data);
			return (false);
		}
		data->philo[i].data = data;
		i++;
	}
	return (true);
}

bool	can_init_philo_data(t_data *data)
{
	if (!init_philo_data(data))
	{
		print_error("Failed to initialize philo_data.\n");
		exit_flag(data);
		return (false);
	}
	return (true);
}
