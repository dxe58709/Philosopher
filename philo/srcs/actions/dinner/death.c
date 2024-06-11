/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:49:47 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/11 16:15:11 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_philosopher_death(t_philo *philo, unsigned int time_to_die)
{
	unsigned int	last_meal_time;

	last_meal_time = update_last_meal_time(philo);
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
	while (!check_stop_condition(data))
	{
		i = 0;
		while (i < data->args.number_of_philo)
		{
			if (check_philosopher_death(&data->philo[i],
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
