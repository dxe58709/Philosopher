/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:28:56 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/10 20:29:24 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dinner.h"

static bool	create_philosopher_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->args.number_of_philo)
	{
		create_thread(&data->threads[i], &philo_routine, &data->philo[i]);
		i++;
	}
	return (true);
}
