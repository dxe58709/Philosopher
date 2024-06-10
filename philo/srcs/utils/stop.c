/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:24:41 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/10 18:56:15 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	check_philo_die(t_data *data)
{
	bool	status;

	pthread_mutex_lock(&data->stop_mtx);
	status = data->stop;
	pthread_mutex_unlock(&data->stop_mtx);
	return (status);
}

void	set_stop(t_data *data)
{
	pthread_mutex_lock(&data->stop_mtx);
	data->stop = true;
	pthread_mutex_unlock(&data->stop_mtx);
}
