/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:06:40 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/13 17:25:11 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	start_dinner(t_data *data)
{
	if (!create_philo_threads(data))
	{
		print_error("Failed to create threads.\n");
		return (false);
	}
	if (pthread_create(&data->monitor, NULL, monitor_philos, (void *)data))
	{
		print_error("Failed to create monitor threads.\n");
		return (false);
	}
	return (true);
}
