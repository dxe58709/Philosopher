/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:49:47 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/17 20:45:45 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	over_time_to_die(t_philo *philo, unsigned int time_to_die)
{
	pthread_mutex_lock(&philo->last_meal_time_mtx);
	if (time_to_die < get_current_time() - philo->last_meal_time)
	{
		print_message("died", philo);
		exit_flag(philo->data);
		pthread_mutex_unlock(&philo->last_meal_time_mtx);
		return (true);
	}
	pthread_mutex_unlock(&philo->last_meal_time_mtx);
	return (false);
}

void	*monitor_philos(void *args)
{
	t_data			*data;
	unsigned int	i;

	data = (t_data *)args;
	while (!data->exit_flag && !check_philo_die(data))
	{
		i = 0;
		while (i < data->args.number_of_philo)
		{
			if (over_time_to_die(&data->philo[i],
					data->args.time_to_die))
				return (NULL);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
