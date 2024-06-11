/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:49:47 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/11 17:04:19 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static unsigned int	get_last_eaten_time(t_philo *philo)
{
	unsigned int	last_eaten_time;

	pthread_mutex_lock(&philo->last_meal_time_mtx);
	philo->last_meal_time = get_current_time();
	last_eaten_time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->last_meal_time_mtx);
	return (last_eaten_time);
}

static bool	check_time_to_die(t_philo *philo, unsigned int time_to_die)
{
	unsigned int	last_meal_time;

	last_meal_time = get_last_eaten_time(philo);
	if (time_to_die < last_meal_time)
	{
		print_message("died", philo);
		return (true);
	}
	return (false);
}

void	*monitor_philos(void *args)
{
	t_data			*data;
	unsigned int	i;

	data = (t_data *)args;
	while (!check_philo_die(data))
	{
		i = 0;
		while (i < data->args.number_of_philo)
		{
			if (check_time_to_die(&data->philo[i],
					data->args.time_to_die))
			{
				set_stop(data);
				return (NULL);
			}
			i++;
		}
		usleep(100);
	}
	return (NULL);
}
