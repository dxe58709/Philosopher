/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_dinner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:38:11 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/14 01:30:31 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	can_dinner(t_data *data, int argc, char **argv)
{
	data->exit_flag = false;
	if (check_correct_args(argc, argv, data))
	{
		if (!can_init_thread(data))
			return (false);
		if (!can_init_mutex(data))
			return (false);
		if (!can_init_args(argc, argv, data))
			return (false);
		if (!can_init_philo_data(data))
			return (false);
	}
	return (true);
}
