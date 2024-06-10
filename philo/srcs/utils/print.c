/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:01:37 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/10 18:56:43 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_message(char *str, t_philo *philo)
{
	unsigned int	ms_timestamps;

	pthread_mutex_lock(&philo->data->print_mtx);
	if (!check_philo_die(philo->data))
	{
		ms_timestamps = get_current_time() - philo->data->starting_time;
		printf("%d %d %s\n", ms_timestamps, philo->philo_id, str);
	}
	pthread_mutex_unlock(&philo->data->print_mtx);
}
