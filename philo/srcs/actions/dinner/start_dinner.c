/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:06:40 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/13 22:30:26 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	start_dinner(t_data *data)
{
	unsigned int	i;

	i = 0;
	data->starting_time = get_current_time();
	while (i < data->args.number_of_philo)
	{
		if (!create_thread(&data->threads[i], &philo_routine, &data->philo[i]))
		{
			print_error("Failed to create threads.\n");
			return ;
		}
		i++;
	}
	if (1 < data->args.number_of_philo)
	{
		if (!create_thread(&data->monitor, monitor_philos, data))
		{
			print_error("Failed to create monitor threads.\n");
			return ;
		}
	}
}
