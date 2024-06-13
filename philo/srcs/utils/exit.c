/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:24:41 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/13 18:29:26 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_philo_die(t_data *data)
{
	bool	status;

	pthread_mutex_lock(&data->exit_flag_mtx);
	status = data->exit_flag;
	pthread_mutex_unlock(&data->exit_flag_mtx);
	return (status);
}

void	exit_flag(t_data *data)
{
	pthread_mutex_lock(&data->exit_flag_mtx);
	data->exit_flag = true;
	pthread_mutex_unlock(&data->exit_flag_mtx);
}
