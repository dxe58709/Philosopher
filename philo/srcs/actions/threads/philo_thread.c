/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:28:56 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/13 20:33:35 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	create_philo_threads(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->args.number_of_philo)
	{
		if (!create_thread(&data->threads[i], &philo_routine, &data->philo[i]))
		{
			exit_flag(data);
			while (0 < i)
			{
				join_thread(data->threads[i]);
				i--;
			}
			return (false);
		}
		i++;
	}
	i = 0;
	while (i < data->args.number_of_philo)
	{
		if (!join_thread(data->threads[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	join_philo_threads(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->args.number_of_philo)
	{
		if (!join_thread(data->threads[i]))
			return (false);
		i++;
	}
	return (true);
}
