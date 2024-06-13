/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moniter_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:34:56 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/13 21:35:32 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	create_monitor_threads(t_data *data)
{
	if (!create_thread(&data->monitor, &monitor_philos, data))
		return (false);
	return (true);
}

bool	join_monitor_threads(t_data *data)
{
	if (!join_thread(data->monitor))
		return (false);
	return (true);
}
